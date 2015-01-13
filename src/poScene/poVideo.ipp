//
//  poVideo.cpp
//  Video
//
//  Created by Stephen Varga on 6/17/14.
//
//

#include "poVideo.h"


namespace po {
    template<class T>
    std::shared_ptr<Video<T> > Video<T>::create() {
        std::shared_ptr<Video<T> > ref = std::shared_ptr<Video<T> >(new Video());
        ref->setup();
        return ref;
    }
    
    
    template<class T>
    std::shared_ptr<Video<T> > Video<T>::create(GenericMovieRef movieRef) {
        std::shared_ptr<Video<T> > ref = std::shared_ptr<Video<T> >(new Video());
        ref->setup();
        ref->setMovieRef(movieRef);
        return ref;
    }
    
    
    template<class T>
    void Video<T>::setup() {}
    
    
    template<class T>
    void Video<T>::update() {}
    
    
    template<class T>
    ci::Rectf Video<T>::getBounds()
    {
        GenericMovieRef m = mMovieRef.lock();
        if(m) return m->getBounds();
        return ci::Rectf(0,0,0,0);
    }
    
    
    template<class T>
    void Video<T>::draw()
    {
        GenericMovieRef m = mMovieRef.lock();
        if(m && m->getTexture()) {
            ci::gl::color(ci::ColorA(getFillColor(), getAppliedAlpha()));
            ci::gl::draw(m->getTexture());
        }
    }
}