#ifndef DUMPFUNCTIONS_H
#define DUMPFUNCTIONS_H

extern "C"
{
    #include "zcl.h"

    void vDumpZclReadRequest(tsZCL_CallBackEvent *psEvent);
    void vDumpZclWriteAttributeRequest(tsZCL_CallBackEvent *psEvent);
    void vDumpAfEvent(ZPS_tsAfEvent* psStackEvent);
    void vDumpNetworkParameters();
    void vDisplayDiscoveredNodes();
    void vDisplayNeighbourTable();
    void vDisplayBindTable();
    void vDisplayAddressMap();
}


#endif // DUMPFUNCTIONS_H
