//
//  BaseModel.cpp
//  ccHelp_ios_mac
//
//  Created by Vinova on 7/7/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#include "BaseModel.h"

namespace ccHelp {
    BaseModel::BaseModel(KVDB *db, const std::string &kp)
    : Model(db), keyPath(kp)
    {
    }
}