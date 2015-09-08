#include "ofMain.h"
#include "ofxJpegCollapse.h"

class ofApp : public ofBaseApp{
    bool bAutoReload;
    string fileName;
    ofxJpegCollapse collapse;
public:
    void setup() {
        bAutoReload = true;
        fileName = "Lenna.jpg";
        collapse.load(fileName, 10, 0);
    }
    void update() {
        if(bAutoReload) {
            int end = (cos(ofGetFrameNum() * 0.4f) + 1.0f) * 31.5f + 1;
            collapse.load(fileName, end, 0);
        }
    }
    void draw() {
        ofBackground(ofColor::black);
        ofSetColor(ofColor::white);
        if(collapse.isAllocated()) {
            collapse.draw(0, 0);
        }
    }
    
    void keyPressed(int key) {
        if(key == ' ') {
            int begin = rand() % 8, end = rand() % 16 + 8;
            collapse.load(fileName, end, begin);
        }
        if(key == 'a') {
            bAutoReload ^= true;
        }
    }
};

int main() {
    ofSetupOpenGL(512, 512, OF_WINDOW);
    ofRunApp(new ofApp());
}
