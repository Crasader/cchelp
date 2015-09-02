//
//  Model.cpp
//  ccHelp_ios_mac
//
//  Created by Vinova on 7/7/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#include "Model.h"

namespace ccHelp
{
    Model::Model(KVDB *_db)
    : db(_db) {}
    
    Model::~Model() {}
    
    KVDB* Model::getDB() const
    {
        return db;
    }
}