#include<iostream>
#include<string>
#include<vector>

using namespace std;

class MusicPlayer;

// State
class State {
    public:
    virtual void play(MusicPlayer* player) = 0;
    virtual void pause(MusicPlayer* player) = 0;
};

// Context
class MusicPlayer {
    private:
    State* curentState;
    
    public:
    void setState(State* state) { curentState = state; }
    void play() { curentState->play(this); }
    void pause() { curentState->pause(this); }
};

// ConcreteState
class PausedState;
class PlayingState : public State {
    public:
    void play(MusicPlayer* player) override {
        cout << "Already playing" << endl;
    }
    void pause(MusicPlayer* player) override;
};
class PausedState : public State {
    public:
    void play(MusicPlayer* player) override;
    void pause(MusicPlayer* player) override {
        cout << "Already paused" << endl;
    }
};

void PlayingState::pause(MusicPlayer* player) {
    cout << "Pausing..." << endl;
    player->setState(new PausedState());
}
void PausedState::play(MusicPlayer* player) {
    cout << "Playing..." << endl;
    player->setState(new PlayingState());
}

int main() {
    MusicPlayer player;
    player.setState(new PlayingState());
    player.play();
    player.pause();
    player.pause();
    player.play();
    player.play();
    return 0;
}

/* Output: */
/*
Already playing
Pausing...
Already paused
Playing...
Already playing
*/