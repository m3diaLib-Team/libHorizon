#include "horizon/core/input.hpp"

namespace horizon {
    Input::InputData Input::m_inputData;

    void Input::scanInput() {
        hidScanInput();
        u32 keysDown, keysHeld, keysUp;

        for(short int i = 0; i < (short int) Player::All; ++i) {
            if (isPlayerConnected((Player) i)) {
                keysDown = hidKeysDown((HidControllerID) i);
                keysHeld = hidKeysHeld((HidControllerID) i);
                keysUp   = hidKeysUp((HidControllerID) i);

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
