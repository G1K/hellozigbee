#ifndef ZIGBEEDEVICE_H
#define ZIGBEEDEVICE_H

#include "PersistedValue.h"
#include "PdmIds.h"
#include "PollTask.h"
#include "Queue.h"

extern "C"
{
    #include "zps_gen.h"
    #include "zps_apl_af.h"
    #include "bdb_api.h"

    // work around of a bug in appZpsBeaconHandler.h that does not have a closing } for its extern "C" statement
    }
}

class ZigbeeDevice
{
    typedef enum
    {
        NOT_JOINED,
        JOINING,
        JOINED

    } JoinStateEnum;

    PersistedValue<JoinStateEnum, PDM_ID_NODE_STATE> connectionState;
    Queue<BDB_tsZpsAfEvent, 3> bdbEventQueue;
    PollTask pollTask;

    bool polling;

public:
    ZigbeeDevice();

    static ZigbeeDevice * getInstance();

    void start();

    void joinNetwork();
    void leaveNetwork();
    void joinOrLeaveNetwork();

    void pollParent();
    bool canSleep() const;

protected:
    void handleNetworkJoinAndRejoin();
    void handleLeaveNetwork();
    void handleRejoinFailure();
    void handlePollResponse(ZPS_tsAfPollConfEvent* pEvent);
    void handleZdoBindEvent(ZPS_tsAfZdoBindEvent * pEvent);
    void handleZdoUnbindEvent(ZPS_tsAfZdoUnbindEvent * pEvent);
    void handleZdoDataIndication(ZPS_tsAfEvent * pEvent);
    void handleZdoEvents(ZPS_tsAfEvent* psStackEvent);
    void handleZclEvents(ZPS_tsAfEvent* psStackEvent);
    void handleAfEvent(BDB_tsZpsAfEvent *psZpsAfEvent);

public:
    void handleBdbEvent(BDB_tsBdbEvent *psBdbEvent);
};

#endif // ZIGBEEDEVICE_H