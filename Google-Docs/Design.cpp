#include<bits/stdc++.h>
using namespace std;

class Text{
    string text;
public:
    Text(string text){
        this->text = text;
    }
    string getText(){
        return this->text;
    }
};

class Document{ // interface
public:
    virtual void addText(Text * t) = 0;
    virtual void removeText(Text * t) = 0;
    virtual void viewDoc() = 0;
    virtual ~Document(){};
};
class SimpleDoc : public Document{
    vector<Text*> doc;
public:
    SimpleDoc(){

    }
    SimpleDoc(vector<Text*> doc){
        this->doc = doc;
    }
    void addText(Text * t) override{
        doc.push_back(t);
        cout<<"text added successfully."<<endl;
        cout<<t->getText()<<endl;
    }
    void removeText(Text *t)override {
        for(int i=0;i<doc.size();i++){
            Text * text = doc[i];
            if(text->getText()==t->getText()) {
                doc.erase(doc.begin()+i);
                cout<<"Removed Text: "<<text->getText()<<endl;
                return;
            }
        }
    }
    void viewDoc() override {
        cout<<"--------Simple Document--------------"<<endl;
        for(auto d: doc){
            cout<<d->getText()<<endl;
        }
    }
};

class Database{ // interface
public:
    virtual void saveFile(Document *doc) = 0;
    virtual void viewDatabase() = 0;
    virtual ~Database(){};
};
class Cloud: public Database{
    vector<Document*>dcoumentList;
public:
    Cloud(){

    }
    Cloud(vector<Document*>dcoumentList){
        this->dcoumentList = dcoumentList;
    }
    void saveFile(Document *doc) override {
        dcoumentList.push_back(doc);
    }
    void viewDatabase() override {
        int i=1;
        cout<<"---------Database Snap--------------"<<endl;
        for(auto doc: dcoumentList){
            cout<<i<<". ";
            doc->viewDoc();
            i++;
        }
    }
};


int main(){
    Cloud * cloudDB = new Cloud();

    SimpleDoc * simpleDoc = new SimpleDoc();
    Text * t = new Text("My name is Vivek");
    simpleDoc->addText(t);
    simpleDoc->addText(new Text("I live in bangalore."));
    simpleDoc->addText(new Text("I work with passion."));
    simpleDoc->viewDoc();


    SimpleDoc * simpleDoc2 = new SimpleDoc();
    t = new Text("My name is Ankit");
    simpleDoc2->addText(t);
    simpleDoc2->addText(new Text("I live in Pune."));
    simpleDoc2->addText(new Text("I work with honesty."));
    simpleDoc2->viewDoc();

    cloudDB->saveFile(simpleDoc);
    cloudDB->saveFile(simpleDoc2);
    cloudDB->viewDatabase();

}