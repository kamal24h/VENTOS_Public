/****************************************************************************/
/// @file    Base.h
/// @author  Mani Amoozadeh <maniam@ucdavis.edu>
/// @author  second author name
/// @date    August 2013
///
/****************************************************************************/
// VENTOS, Vehicular Network Open Simulator; see http:?
// Copyright (C) 2013-2015
/****************************************************************************/
//
// This file is part of VENTOS.
// VENTOS is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

#ifndef APPLRSU_H_
#define APPLRSU_H_

#include "global/BaseWaveApplLayer.h"
#include "msg/BeaconRSU_m.h"

namespace VENTOS {

class ApplRSUBeacon : public BaseWaveApplLayer
{
protected:
    cModule* TLptr;
    bool signalBeaconing;

    std::string myTLid;
    TraCICoord rsu_pos;

    int TLControlMode = -1;
    double minGreenTime = -1;

private:
    typedef BaseWaveApplLayer super;

public:
    ~ApplRSUBeacon();
    virtual void initialize(int stage);
    virtual void finish();

protected:
    virtual void handleSelfMsg(omnetpp::cMessage* msg);
    virtual void sendBeacon();
    virtual void executeEachTimeStep();

private:
    BeaconRSU* generateBeacon();
};

}

#endif