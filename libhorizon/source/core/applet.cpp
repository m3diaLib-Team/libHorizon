#include <cstring>
#include "horizon/libnx.hpp"
#include "horizon/core/applet.hpp"
#include "horizon/core/input.hpp"

namespace horizon {
    bool Applet::m_running = false;
    int Applet::m_currentFrame = 0;
    int Applet::m_nxlinkSock = 0;

    Applet::Applet(bool enableNxlinkStdio) {
             if (!m_running) {
                 if (enableNxlinkStdio) initNxLink();
                 appletInitializeGamePlayRecording();

                 m_running = true;
             }
         }

    Applet::~Applet() {
        appletEndBlockingHomeButton();
        socketExit();
        deinitNxLink();
    }

    bool Applet::isRunning() {
        if (!appletMainLoop()) return false;

        Input::scanInput();
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
        AppletStorage outputStorage;
        LibAppletArgs args;

        u8 indata[0xA0] = { 0 };
        indata[0x0] = 0;
        indata[0x96] = 1;

        appletCreateLibraryApplet(&aph, AppletId_playerSelect, LibAppletMode_AllForeground);
        libappletArgsCreate(&args, 0);
        libappletArgsPush(&args, &aph);
        libappletPushInData(&aph, &indata, sizeof(indata));

        appletHolderStart(&aph);

        while (appletHolderWaitInteractiveOut(&aph));

        appletHolderJoin(&aph);
        appletHolderPopOutData(&aph, &outputStorage);
        appletStorageRead(&outputStorage, 0, &outdata, 24);

        appletHolderClose(&aph);
        appletStorageClose(&outputStorage);

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

    Applet::Error::Error() :
        m_title(""),
        m_description(""),
        m_moduleCode(2000),
        m_descriptionCode(0) { /* do nothing */ }

    void Applet::Error::show(const std::string& title, const std::string& description, int descriptionCode, int moduleCode) {
        AppletHolder err;
        LibAppletArgs errArgs;

        appletCreateLibraryApplet(&err, AppletId_error, LibAppletMode_AllForeground);
        libappletArgsCreate(&errArgs, 1);
        libappletArgsPush(&errArgs, &err);

        ErrorConfig c = {0};
        c.customText = true;
        c.module = moduleCode;
        c.description = descriptionCode;
        strncpy(c.shortDescription, title.c_str(), sizeof(c.shortDescription) - 1);
        strncpy(c.detailedDescription, description.c_str(), sizeof(c.detailedDescription) - 1);

        libappletPushInData(&err, &c, sizeof(ErrorConfig));

        appletHolderStart(&err);
        appletHolderJoin(&err);
        appletHolderClose(&err);
    }

    void Applet::Error::show() {
        show(m_title, m_description, m_descriptionCode, m_moduleCode);
    }

    void Applet::Error::setTitle(const std::string& title) {
        m_title = title;
    }

    const std::string& Applet::Error::getTitle() {
        return m_title;
    }

    void Applet::Error::setDescription(const std::string& description) {
        m_description = description;
    }

    const std::string& Applet::Error::getDescription() {
        return m_description;
    }

    void Applet::Error::setModuleCode(int code) {
        m_moduleCode = code;
    }

    int Applet::Error::getModuleCode() {
        return m_moduleCode;
    }

    void Applet::Error::setDescriptionCode(int code) {
        m_descriptionCode = code;
    }

    int Applet::Error::getDescriptionCode() {
        return m_descriptionCode;
    }

    void Applet::Error::setErrorCode(int module, int description) {
        m_moduleCode = module;
        m_descriptionCode = description;
    }

    void Applet::initNxLink()
    {
        if (R_FAILED(socketInitializeDefault()))
            return;

        m_nxlinkSock = nxlinkStdio();
        if (m_nxlinkSock >= 0)
            printf("Stdout now goes to the nxlink server\n");
        else
            socketExit();
    }

    void Applet::deinitNxLink()
    {
        if (m_nxlinkSock >= 0)
        {
            close(m_nxlinkSock);
            socketExit();
            m_nxlinkSock = -1;
        }
    }
} /* horizon */
