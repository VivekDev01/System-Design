#include<bits/stdc++.h>
using namespace std;

// OBSERVER
class IObserver{
public:
    virtual void update() = 0;
    virtual ~IObserver(){};
};

// OBSERVABLE
class IObservable{
public:
    virtual void addObserver(IObserver *observer) = 0;
    virtual void removeObserver(IObserver *observer) =0;
    virtual void notify() = 0;
    virtual ~IObservable(){};
};


class YoutubeChannel : public IObservable{
    vector<IObserver*>observers;
    string latestVideo;
public:
    void addObserver(IObserver *observer) override{
        observers.push_back(observer);
    }

    void removeObserver(IObserver *observer) override{
        for(int i=0;i<observers.size();i++){
            if(observers[i]==observer){
                observers.erase(observers.begin() + i);
            }
        }
    }

    void notify() override{
        for(auto it: observers){
            it->update();
        }
    }

    void setVideo(string latestVideo){
        this->latestVideo = latestVideo;
        notify();
    }

    void getVideo(){
        cout<<"new latest Video is uploaded : "<<latestVideo<<endl;
    }
};


class Subsciber : public IObserver{
    string name;
    YoutubeChannel *channel;
public:
    Subsciber(string name){
        this->name = name;
    }
    void subscribeChannel(YoutubeChannel *channel){
        this->channel = channel;
    }
    void update() override{
        cout<<"hey "<<name<<" ";
        channel->getVideo();
    }
};





int main(){
    YoutubeChannel *Tseries = new YoutubeChannel();

    Subsciber *vivek = new Subsciber("Vivek");
    Subsciber *ankit = new Subsciber("Ankit");

    vivek->subscribeChannel(Tseries);
    ankit->subscribeChannel(Tseries);

    Tseries->addObserver(vivek);
    Tseries->addObserver(ankit);

    Tseries->setVideo("Yoyo honey singh song");
    
    cout<<"--------X--------------X---------X----------"<<endl;
    
    Tseries->setVideo("Jai ho");
}
