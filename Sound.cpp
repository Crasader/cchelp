//
//  Sound.cpp
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 3/31/15.
//
//

#include "Sound.h"
#include "SimpleAudioEngine.h"
#include "cocos2d.h"

USING_NS_CC;
using namespace std;
using namespace CocosDenshion;

namespace ccHelp {
    Sound* Sound::inst = new Sound;
    string Sound::KEY_BGM_VOL_STATE = "BGMVolume";
    string Sound::KEY_EFF_VOL_STATE = "EffectVolume";
    std::function<std::string(const std::string&)> Sound::FILE_FROM_NAME =
    [](const std::string &name) -> std::string {
        return cocos2d::StringUtils::format("%s.mp3", name.c_str());
    };
    const uint Sound::BACKGROUND_ID = 0xffffffff;
    
    Sound* Sound::getInstance()
    {
        return inst;
    }
    
    void Sound::load()
    {
        setVolume(UserDefault::getInstance()->getFloatForKey(KEY_BGM_VOL_STATE.c_str(), 1.f), SoundType::BACKGROUND);
        setVolume(UserDefault::getInstance()->getFloatForKey(KEY_EFF_VOL_STATE.c_str(), 1.f), SoundType::EFFECT);
    }
    
    void Sound::save()
    {
        UserDefault::getInstance()->flush();
    }
    
    void Sound::playBackgroundMusic(const std::string &name, bool loop) const
    {
        this->play(name, SoundType::BACKGROUND, loop);
    }
    
    uint Sound::playEffect(const std::string &name, bool loop) const
    {
        return this->play(name, SoundType::EFFECT, loop);
    }
    
    void Sound::pauseEffect(uint _id) const
    {
        this->pause(_id);
    }
    
    void Sound::resumeEffect(uint _id) const
    {
        this->resume(_id);
    }
    void Sound::stopEffect(uint _id) const
    {
        this->stop(_id);
    }
    
    void Sound::pauseBackgroundMusic() const
    {
        this->pause(BACKGROUND_ID);
    }
    
    void Sound::resumeBackgroundMusic() const
    {
        this->resume(BACKGROUND_ID);
    }
    
    uint Sound::play(const std::string &name, SoundType type, bool loop) const
    {
        if (type == SoundType::BACKGROUND)
        {
            SimpleAudioEngine::getInstance()->playBackgroundMusic(FILE_FROM_NAME(name).c_str(),
                                                                  loop);
            return BACKGROUND_ID;
        }
        else if (type == SoundType::EFFECT)
        {
            return SimpleAudioEngine::getInstance()->playEffect(FILE_FROM_NAME(name).c_str(), loop);
        }
        
        return 0U;
    }
    
    void Sound::pause(uint _id) const
    {
        if (_id == BACKGROUND_ID)
        {
            SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
        }
        else
        {
            SimpleAudioEngine::getInstance()->pauseEffect(_id);
        }
    }
    
    void Sound::resume(uint _id) const
    {
        if (_id == BACKGROUND_ID)
        {
            SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
        }
        else
        {
            SimpleAudioEngine::getInstance()->resumeEffect(_id);
        }
    }
    
    void Sound::stop(uint _id) const
    {
        if (_id == BACKGROUND_ID)
        {
            SimpleAudioEngine::getInstance()->stopBackgroundMusic();
        }
        else
        {
            SimpleAudioEngine::getInstance()->stopEffect(_id);
        }
    }
    
    float Sound::getVolume(SoundType type) const
    {
        switch (type) {
            case BACKGROUND:
                return SimpleAudioEngine::getInstance()->getBackgroundMusicVolume();
            case EFFECT:
                return SimpleAudioEngine::getInstance()->getEffectsVolume();
            case BOTH:
                return max(getVolume(SoundType::BACKGROUND), getVolume(SoundType::EFFECT));
        }
        
        return 0.f;
    }
    
    void Sound::setVolume(float vol, SoundType type) const
    {
        switch (type) {
            case BACKGROUND:
                SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(vol);
                UserDefault::getInstance()->setBoolForKey(KEY_BGM_VOL_STATE.c_str(), vol > 0);
                break;
            case EFFECT:
                SimpleAudioEngine::getInstance()->setEffectsVolume(vol);
                UserDefault::getInstance()->setBoolForKey(KEY_EFF_VOL_STATE.c_str(), vol > 0);
                break;
            case BOTH:
                setVolume(vol, SoundType::BACKGROUND);
                setVolume(vol, SoundType::EFFECT);
                break;
        }
    }
}