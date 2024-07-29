#include <iostream>

// Target Interface
class MediaPlayer {
public:
    virtual void play(const std::string& audioType, const std::string& fileName) = 0;
    virtual ~MediaPlayer() {}
};

// Adaptee
class AdvancedMediaPlayer {
public:
    virtual void playMp4(const std::string& fileName) = 0;
    virtual void playVlc(const std::string& fileName) = 0;
    virtual ~AdvancedMediaPlayer() {}
};

class VlcPlayer : public AdvancedMediaPlayer {
public:
    void playVlc(const std::string& fileName) override {
        std::cout << "Playing vlc file. Name: " << fileName << std::endl;
    }
    void playMp4(const std::string&) override {}
};

class Mp4Player : public AdvancedMediaPlayer {
public:
    void playMp4(const std::string& fileName) override {
        std::cout << "Playing mp4 file. Name: " << fileName << std::endl;
    }
    void playVlc(const std::string&) override {}
};

// Adapter
class MediaAdapter : public MediaPlayer {
    AdvancedMediaPlayer* advancedPlayer;
public:
    MediaAdapter(const std::string& audioType) {
        if (audioType == "vlc") {
            advancedPlayer = new VlcPlayer();
        } else if (audioType == "mp4") {
            advancedPlayer = new Mp4Player();
        } else {
            advancedPlayer = nullptr;
        }
    }
    void play(const std::string& audioType, const std::string& fileName) override {
        if (audioType == "vlc") {
            advancedPlayer->playVlc(fileName);
        } else if (audioType == "mp4") {
            advancedPlayer->playMp4(fileName);
        }
    }
    ~MediaAdapter() { delete advancedPlayer; }
};

// Client Code
int main() {
    MediaPlayer* player = new MediaAdapter("mp4");
    player->play("mp4", "example.mp4");
    delete player;

    player = new MediaAdapter("vlc");
    player->play("vlc", "example.vlc");
    delete player;

    return 0;
}

