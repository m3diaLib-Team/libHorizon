/**
 * @file core/input.hpp
 * @brief Defines the Input class
 */
#ifndef CORE_INPUT_H
#define CORE_INPUT_H

#pragma once

#include "horizon/libnx.hpp"

namespace horizon {
    /**
     * @brief Handles user input
     */
    class Input {
    friend class Applet;
    public:
        /**
         * @brief Represents the different buttons
         */
        enum Button {
            A = (1U<<( 0 )),                                      ///< A
            B = (1U<<( 1 )),                                      ///< B
            X = (1U<<( 2 )),                                      ///< X
            Y = (1U<<( 3 )),                                      ///< Y
            LeftStick = (1U<<( 4 )),                              ///< Left stick pressed
            RightStick = (1U<<( 5 )),                             ///< Right stick pressed
            L = (1U<<( 6 )),                                      ///< L
            R = (1U<<( 7 )),                                      ///< R
            ZL = (1U<<( 8 )),                                     ///< ZL
            ZR = (1U<<( 9 )),                                     ///< ZR
            Plus = (1U<<( 10 )),                                  ///< Plus
            Minus = (1U<<( 11 )),                                 ///< Minus
            DPadLeft = (1U<<( 12 )),                              ///< D-Pad left
            DPadUp = (1U<<( 13 )),                                ///< D-Pad up
            DPadRight = (1U<<( 14 )),                             ///< D-Pad right
            DPadDown = (1U<<( 15 )),                              ///< D-Pad down
            LeftStickLeft = (1U<<( 16 )),                         ///< Left stick left
            LeftStickUp = (1U<<( 17 )),                           ///< Left stick up
            LeftStickRight = (1U<<( 18 )),                        ///< Left stick right
            LeftStickDown = (1U<<( 19 )),                         ///< Left stick down
            RightStickLeft = (1U<<( 20 )),                        ///< Right stick left
            RightStickUp = (1U<<( 21 )),                          ///< Right stick up
            RightStickRight = (1U<<( 22 )),                       ///< Right stick right
            RightStickDown = (1U<<( 23 )),                        ///< Right stick down
            Up = DPadUp | LeftStickUp | RightStickUp,             ///< Up
            Down = DPadDown | LeftStickDown | RightStickDown,     ///< Down
            Left = DPadLeft | LeftStickLeft | RightStickLeft,     ///< Left
            Right = DPadRight | LeftStickRight | RightStickRight, ///< Right
            LeftSL = (1U<<( 24 )),                                ///< SL on the left JoyCon
            LeftSR = (1U<<( 25 )),                                ///< SR on the left JoyCon
            RightSL = (1U<<( 26 )),                               ///< SL on the right JoyCon
            RightSR = (1U<<( 27 )),                               ///< SR on the right JoyCon
            SL = LeftSL | RightSL,                                ///< SL
            SR = LeftSR | RightSR,                                ///< SR
            Touch = (1U<<( 28 )),                                 ///< Touch (only whether the user touches *somewhere* on the screen)
        };

        /**
         * @brief Represents the different players
         */
        enum class Player: int {
            P1 = 0,   // Player 1
            P2,       // Player 2
            P3,       // Player 3
            P4,       // Player 4
            P5,       // Player 5
            P6,       // Player 6
            P7,       // Player 7
            P8,       // Player 8
            Handheld, // Handheld
            All       // All players
        };

        /**
         * @brief Contains all the input data for the current frame
         */
        struct InputData {
            /**
             * @brief Contains input data on a per-player basis
             */
            struct PlayerInput {
                /**
                 * @brief Contains all the information about this player's controller
                 */
                struct ControllerData {
                    bool connected; ///< Whether a controller is connected on this slot
                };

                int pressedButtons,  ///< Buttons that have been pressed by this player this frame
                    downButtons,     ///< Buttons that are pressed by this player this frame, regardless whether they were pressed in the last frame or not
                    releasedButtons; ///< Buttons that have been released by this player this frame
                ControllerData controllerData; ///< Controller data
            };

            int pressedButtons,  ///< Buttons that have been pressed by any player this frame
                downButtons,     ///< Buttons that are pressed by any player this frame, regardless whether they were pressed in the last frame or not
                releasedButtons; ///< Buttons that have been released by any player this frame
            PlayerInput playerData[(int) Player::All]; ///< Input data for every player
        };

        /**
         * @brief Returns whether the console is being used in handheld mode
         * @return `true` if the console is being used in handheld mode, `false` otherwise
         */
        static inline bool isHandheld() {
            return (hidGetHandheldMode() == 1 ? true : false);
        }

        /**
         * @brief Returns whether a controller is connected on the given player slot
         * @param  player The player to check
         * @return        `true` if the given player is connected, `false` otherwise
         */
        static inline bool isPlayerConnected(Player player) {
            return hidIsControllerConnected((HidControllerID) player);
        }

        /**
         * @brief Gets the buttons down in bits
         * @param  player The player to read the buttons from
         * @return        Button values in bits
         */
        static inline u32 buttonsDown(Player player = Player::All) {
            return (player == Player::All ? m_inputData.releasedButtons : m_inputData.playerData[(int) player].downButtons);
        }

        /**
         * @brief Gets the buttons pressed in bits
         * @param  player The player to read the buttons from
         * @return        Button values in bits
         */
        static inline u32 buttonsPressed(Player player = Player::All) {
            return (player == Player::All ? m_inputData.releasedButtons : m_inputData.playerData[(int) player].pressedButtons);
        }

        /**
         * @brief Gets the buttons released in bits
         * @param  player The player to read the buttons from
         * @return        Button values in bits
         */
        static inline u32 buttonsReleased(Player player = Player::All) {
            return (player == Player::All ? m_inputData.releasedButtons : m_inputData.playerData[(int) player].releasedButtons);
        }

        /**
         * Returns whether the given button is pressed this frame but wasn't pressed in the last frame
         * @param  buttons The button
         * @param  player  The player to read the buttons from
         * @return         Whether the button is pressed or not
         */
        static inline bool buttonPressed(Button buttons, Player player = Player::All) {
            return (buttonsPressed(player) & buttons);
        }

        /**
         * @brief Returns whether the given button is pressed this frame regardless whether it was pressed in the last frame
         * @param  buttons The button
         * @param  player  The player to read the buttons from
         * @return         Whether the button is pressed or not
         */
        static inline bool buttonDown(Button buttons, Player player = Player::All) {
            return (buttonsDown(player) & buttons);
        }

        /**
         * @brief Returns whether the given button was released (i.e. isn't pressed this frame but was in the last frame)
         * @param  buttons The button
         * @param  player  The player to read the buttons from
         * @return         Whether the button was released or not
         */
        static inline bool buttonReleased(Button buttons, Player player = Player::All) {
            return (buttonsReleased(player) & buttons);
        }

    private:
        static void scanInput();
        static InputData m_inputData;
    };
}

#endif
