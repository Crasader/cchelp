//
//  BaseModel.h
//  ccHelp_ios_mac
//
//  Created by Vinova on 7/7/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#pragma once
#include "Model.h"

namespace ccHelp {
    class BaseModel : public Model
    {
    private:
        std::string keyPath;
        
    protected:
        template <typename T>
        T get(const std::string &k) const;
        
        template <typename T>
        void set(const std::string &k, T value);
        
    public:
        BaseModel(KVDB *db, const std::string &kp);
        
        virtual void fork() const override;
    };
    
    
}