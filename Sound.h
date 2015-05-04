//
//  Sound.h
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 3/31/15.
//
//

#ifndef __GodRage_Endless_Revamp__Sound__
#define __GodRage_Endless_Revamp__Sound__

#pragma once
#include <string>
#include <functional>

namespace ccHelp {
    enum SoundType
    {
        BOTH,
        BACKGROUND,
        EFFECT
    };
    
    class Sound
    {
    private:
        Sound() {}    // private constructor for singleton
        static Sound* inst;
        
    public:
        static const uint BACKGROUND_ID;
        static std::string KEY_BGM_VOL_STATE, KEY_EFF_VOL_STATE;
        static std::function<std::string(const std::string&)> FILE_FROM_NAME;
        static Sound* getInstance();
        
        void load();
        void save();
        
        // play
        void playBackgroundMusic(const std::string &name, bool loop = true) const;
        uint playEffect(const std::string &name, bool loop = false) const;
        
        void pauseEffect(uint _id) const;
        void resumeEffect(uint _id) const;
        void stopEffect(uint _id) const;
        
        void pauseBackgroundMusic() const;
        void resumeBackgroundMusic() const;
        
        uint play(const std::string &name, SoundType type, bool loop = false) const;
        void pause(uint _id) const;
        void resume(uint _id) const;
        void stop(uint _id) const;
        
        float getVolume(SoundType type = BOTH) const;
        void setVolume(float vol, SoundType type = BOTH) const;
        
        inline bool isSoundOn()  const {return getVolume() > 0;}
        inline bool isMute()  const {return !isSoundOn();}
        
        inline void turnSoundOn(SoundType type = BOTH) const {setVolume(1.f, type);}
        inline void turnSoundOff(SoundType type = BOTH) const {setVolume(0.f, type);}
    };
}

#endif /* defined(__GodRage_Endless_Revamp__Sound__) */
