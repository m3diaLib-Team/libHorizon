#include "horizon/core/input.hpp"

namespace horizon {
    Input::InputData Input::m_inputData;

    void Input::scanInput() {
        hidScanInput();
        u32 keysDown, keysHeld, keysUp;

        for(short int i = 0; i < (short int) Player::All; ++i) {
            keysDown = hidKeysDown((HidControllerID) i);
            keysHeld = hidKeysHeld((HidControllerID) i);
            keysUp   = hidKeysUp((HidControllerID) i);

            m_inputData.pressedButtons  |= keysDown;
            m_inputData.downButtons     |= keysHeld;
            m_inputData.releasedButtons |= keysUp;

            m_inputData.playerData[i].pressedButtons  = keysDown;
            m_inputData.playerData[i].downButtons     = keysHeld;
            m_inputData.playerData[i].releasedButtons = keysUp;
        }
    }
} /* horizon */
