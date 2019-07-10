#include "horizon/core/input.hpp"

#define DPAD_TO_LETTER(mask, direction, letter) \
    if (mask & direction) {          \
        mask &= ~direction;          \
        mask &= letter;              \
    }

namespace horizon {
    Input::InputData Input::m_inputData;

    void Input::scanInput() {
        hidScanInput();
        u32 keysDown, keysHeld, keysUp;

        m_inputData.pressedButtons  = 0;
        m_inputData.downButtons     = 0;
        m_inputData.releasedButtons = 0;

        for(short int i = 0; i < (short int) Player::All; ++i) {
            if (isPlayerConnected((Player) i)) {
                keysDown = hidKeysDown((HidControllerID) i);
                keysHeld = hidKeysHeld((HidControllerID) i);
                keysUp   = hidKeysUp((HidControllerID) i);

                // since there are only d-pad buttons on the left Joy-Con, we need to convert those to A/B/X/Y-presses
                if (hidGetControllerType((HidControllerID) i) == TYPE_JOYCON_LEFT) {
                    // Y
                    DPAD_TO_LETTER(keysDown, Button::DPadLeft, Button::Y)
                    DPAD_TO_LETTER(keysHeld, Button::DPadLeft, Button::Y)
                    DPAD_TO_LETTER(keysUp, Button::DPadLeft, Button::Y)

                    // A
                    DPAD_TO_LETTER(keysDown, Button::DPadRight, Button::A)
                    DPAD_TO_LETTER(keysHeld, Button::DPadRight, Button::A)
                    DPAD_TO_LETTER(keysUp, Button::DPadRight, Button::A)

                    // X
                    DPAD_TO_LETTER(keysDown, Button::DPadUp, Button::X)
                    DPAD_TO_LETTER(keysHeld, Button::DPadUp, Button::X)
                    DPAD_TO_LETTER(keysUp, Button::DPadUp, Button::X)

                    // B
                    DPAD_TO_LETTER(keysDown, Button::DPadDown, Button::B)
                    DPAD_TO_LETTER(keysHeld, Button::DPadDown, Button::B)
                    DPAD_TO_LETTER(keysUp, Button::DPadDown, Button::B)
                }

                m_inputData.playerData[i].controllerData.connected = true;
            } else {
                keysDown = 0;
                keysHeld = 0;
                keysUp   = 0;

                m_inputData.playerData[i].controllerData.connected = false;
            }

            m_inputData.pressedButtons  |= keysDown;
            m_inputData.downButtons     |= keysHeld;
            m_inputData.releasedButtons |= keysUp;

            m_inputData.playerData[i].pressedButtons  = keysDown;
            m_inputData.playerData[i].downButtons     = keysHeld;
            m_inputData.playerData[i].releasedButtons = keysUp;
        }
    }
} /* horizon */
