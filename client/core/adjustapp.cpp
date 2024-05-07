#include "adjustapp.h"

adjustapp::adjustapp()
{

}

void adjustapp::setFullScreen(bool fullScreen)
{
    if(fullScreen != isFull_Screen){isFull_Screen = fullScreen;}
}

void adjustapp::fullScreenClicked()
{
    if(!isFull_Screen){
        emit fullScreenChange(!isFull_Screen);
        isFull_Screen = !isFull_Screen;}
    else{
        emit restoreDown(isFull_Screen);
        isFull_Screen = !isFull_Screen;
    }
}

