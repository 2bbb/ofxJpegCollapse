//
//  ofxJpegCollapse.h
//
//  Created by ISHII 2bit on 2015/09/08.
//
//

#ifndef ofxJpegCollapseExample_ofxJpegCollapse_h
#define ofxJpegCollapseExample_ofxJpegCollapse_h

#include "ofMain.h"
#include "jpeg_decoder.h"

class ofxJpegCollapse : public ofImage {
public:
    bool load(const string &path, int end, int begin = 0) {
        ofBuffer buf = ofFile(path).readToBuffer();
        load(buf, end, begin);
    }
    
    bool load(const ofBuffer &buf, int end, int begin = 0) {
        Jpeg::Decoder *decoder = new Jpeg::Decoder((unsigned char *)buf.getBinaryBuffer(), buf.size(), begin, end);
#if JPEG_DECODER_DEBUG
        ofLogNotice() << "decoder result: " << decoder->GetResultString();
#endif
        if(decoder->GetResult() != Jpeg::Decoder::OK) {
            ofLogError("ofxJpegCollapse") << "decode error: " << decoder->GetResultString();
            return false;
        }
#if JPEG_DECODER_DEBUG
        ofLogNotice() << "w, h, size: " << decoder->GetWidth() << ", " << decoder->GetHeight() << ", " << decoder->GetImageSize();
#endif
        setFromPixels(decoder->GetImage(), decoder->GetWidth(), decoder->GetHeight(), decoder->IsColor() ? OF_IMAGE_COLOR : OF_IMAGE_GRAYSCALE);
        delete decoder;
    }
};

#endif
