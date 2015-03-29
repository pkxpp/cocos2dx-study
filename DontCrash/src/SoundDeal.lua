
SoundDeal = {audioEngine = cc.SimpleAudioEngine:getInstance()}

EffectType = {
    Crash = "android_sound/crash.mp3",
    Newhigh = "android_sound/NewHigh.mp3",
    Yes = "android_sound/point01.mp3",
    Start = "android_sound/start.mp3",
    Tap = "android_sound/tap_1.mp3"
}

function SoundDeal:playBg()
    self.audioEngine:playMusic("sound/bg.mp3",true)
    self.audioEngine:setMusicVolume(1)
end

function SoundDeal:stopBg()
    self.audioEngine:stopMusic()
end

function SoundDeal:preloadEffect()
    self.audioEngine:preloadEffect(EffectType.Crash)
    self.audioEngine:preloadEffect(EffectType.Newhigh)
    self.audioEngine:preloadEffect(EffectType.Yes)
    self.audioEngine:preloadEffect(EffectType.Start)
    self.audioEngine:preloadEffect(EffectType.Tap)
    self.audioEngine:setEffectsVolume(1)
end

function SoundDeal:playEffect(type)
    self.audioEngine:playEffect(type)
end
