#ifndef DEFS_H
#define DEFS_H

#include <QString>
namespace birdo
{

    struct AddedVideos
    {
        QString videoName;
        QString videoThumbPath;
        QString videoPath;

        bool isValid() const
        {
            return !videoName.isEmpty() && !videoThumbPath.isEmpty() && !videoPath.isEmpty();
        }
    };

    enum VideoStates
    {
        Stopped = 0,
        Playing = 1,
        Paussed = 2
    };

    enum VolumeStates
    {
        Muted = 0,
        UnMuted = 1
    };
}

#endif // DEFS_H
