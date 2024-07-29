#include <iostream>

// Subsystem components
class Television {
public:
    void on() {
        std::cout << "TV is ON\n";
    }

    void off() {
        std::cout << "TV is OFF\n";
    }
};

class SoundSystem {
public:
    void on() {
        std::cout << "Sound system is ON\n";
    }

    void off() {
        std::cout << "Sound system is OFF\n";
    }

    void setVolume(int level) {
        std::cout << "Volume set to " << level << "\n";
    }
};

class BluRayPlayer {
public:
    void on() {
        std::cout << "BluRay player is ON\n";
    }

    void off() {
        std::cout << "BluRay player is OFF\n";
    }

    void playMovie(const std::string& movie) {
        std::cout << "Playing movie: " << movie << "\n";
    }
};

// Facade class
class HomeTheaterFacade {
    Television tv;
    SoundSystem soundSystem;
    BluRayPlayer bluRayPlayer;

public:
    void watchMovie(const std::string& movie) {
        std::cout << "Get ready to watch a movie...\n";
        tv.on();
        soundSystem.on();
        soundSystem.setVolume(15);
        bluRayPlayer.on();
        bluRayPlayer.playMovie(movie);
    }

    void endMovie() {
        std::cout << "Shutting down the home theater...\n";
        bluRayPlayer.off();
        soundSystem.off();
        tv.off();
    }
};

int main() {
    HomeTheaterFacade homeTheater;
    homeTheater.watchMovie("Inception");
    homeTheater.endMovie();

    return 0;
}

