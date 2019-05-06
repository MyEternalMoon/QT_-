#include "commonfunctions.h"

bool copyFileToPath(QString sourceDir ,QString toDir, bool coverFileIfExist)
{
    toDir.replace("\\","/");
    if (sourceDir == toDir){
        return true;
    }
    if (!QFile::exists(sourceDir)){
        return false;
    }
    QDir *createfile = new QDir;
    bool exist = createfile->exists(toDir);
    if (exist){
        if(coverFileIfExist){
            createfile->remove(toDir);
        }
    }//end if
    delete createfile;
    if(!QFile::copy(sourceDir, toDir))
    {
        return false;
    }

    return true;
}

QPixmap radiusPix(QString url, int size)
{
    QPixmap pixmapa(url);
    QPixmap pixmap(size,size);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    QPainterPath path;
    path.addEllipse(0, 0, size, size);
    painter.setClipPath(path);
    painter.drawPixmap(0, 0, size, size, pixmapa);
    return pixmap;
}

bool isDirExistsAndCreateDir(QString dir)
{
    //����ļ���δ�������򴴽�ͷ���ļ���
    QDir Dir(dir);
    if (!Dir.exists())
        Dir.mkdir(Dir.absolutePath());
    return true;
}
