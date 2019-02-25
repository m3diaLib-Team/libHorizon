#include "horizon/core/applet.hpp"
#include "horizon/core/input.hpp"

namespace horizon {
    Applet::Applet(bool enableNxlinkStdio) :
         m_running(true),
         m_currentFrame(0) {
             consoleInit(NULL);
             socketInitializeDefault();
             if (enableNxlinkStdio) nxlinkStdio();
             appletInitializeGamePlayRecording();
         }

    Applet::~Applet() {
        appletEndBlockingHomeButton();
        socketExit();
        consoleExit(NULL);
    }

    bool Applet::isRunning() {
        if (!appletMainLoop()) return false;

        Input::scanInput();
        consoleUpdate(NULL);
        m_currentFrame++;

        return m_running;
    }

    void Applet::exit() {
        m_running = false;
    }

    int Applet::getCurrentFrame() {
        m_currentFrame = m_currentFrame % 60;
        return m_currentFrame;
    }

    // lib-applets
    void Applet::WiFiSelect::show() {
        AppletHolder applet;

        appletCreateLibraryApplet(&applet, AppletId_netConnect, LibAppletMode_AllForeground);

        appletHolderStart(&applet);
        while (appletHolderWaitInteractiveOut(&applet));
        appletHolderJoin(&applet);
        appletHolderClose(&applet);
    }

    Applet::PlayerSelect::User Applet::PlayerSelect::show() {
        struct UserReturnData {
            u64 result;
            u128 UID;
        } PACKED;

        struct UserReturnData outdata;

        AppletHolder aph;
        AppletStorage ast;
        AppletStorage hast1;
        LibAppletArgs args;

        u8 indata[0xA0] = { 0 };
        indata[0x96] = 1;

        appletCreateLibraryApplet(&aph, AppletId_playerSelect, LibAppletMode_AllForeground);
        libappletArgsCreate(&args, 0);
        libappletArgsPush(&args, &aph);

        appletCreateStorage(&hast1, 0xA0);

        appletStorageWrite(&hast1, 0, indata, 0xA0);
        appletHolderPushInData(&aph, &hast1);
        appletHolderStart(&aph);

        while (appletHolderWaitInteractiveOut(&aph));

        appletHolderJoin(&aph);
        appletHolderPopOutData(&aph, &ast);
        appletStorageRead(&ast, 0, &outdata, 24);

        appletHolderClose(&aph);
        appletStorageClose(&ast);

        AccountProfile profile;
        AccountProfileBase base;
        AccountUserData data;

        accountGetProfile(&profile, outdata.UID);
        accountProfileGet(&profile, &data, &base);

        return {
            base.username,
            (long long int) base.userID,
            data.iconID,
            data.iconBackgroundColorID
        };
    }
} /* horizon */
