//
//  Model.h
//  ccHelp_ios_mac
//
//  Created by Vinova on 7/7/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#pragma once
#include "KVDB.h"

namespace ccHelp {
    class Model
    {
    private:
        KVDB *db;
        
    public:
        Model(KVDB *_db);
        virtual ~Model();
        
        KVDB* getDB() const;
        
        virtual void fork() const = 0;
    };
}