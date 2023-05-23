#include <QJsonValue>
#include <QPdfDocument>
#include <QMessageBox>
#include "picreader.h"
#include "parserInfo.h"

QString PicReader::read(const QString& filename) {
    QString info;
    std::string suffix;
    QString filePathDelSuffix = filename;
    if(filename.contains(".png")){
        filePathDelSuffix.remove(".png");
        suffix = "png";
    }
    else if (filename.contains(".jpg")){
        filePathDelSuffix.remove(".jpg");
        suffix = "jpg";
    }

    QImage image;
    if(filename.contains(".pdf")){
        suffix = "png";//这里用png就好了
        QPdfDocument pdfdoc;
        pdfdoc.load(filename);
        if(!pdfdoc.pageCount()){
            QMessageBox msg;
            msg.setWindowTitle("错误！");
            msg.setWindowFlag(Qt::Drawer);
            msg.setText("文件打开失败！");
            msg.exec();
            return QString{};
        }
        for(int i = 0;i < pdfdoc.pageCount() ;i++){
            image = pdfdoc.render(i,pdfdoc.pagePointSize(i).toSize());
            QString singleImageInfo = parser::parserImage(image,suffix);
            if(singleImageInfo.isEmpty())return QString{};
            info += singleImageInfo;
        }
    } else {
        if(!image.load(filename)){
            QMessageBox msg;
            msg.setWindowTitle("错误！");
            msg.setWindowFlag(Qt::Drawer);
            msg.setText("文件打开失败！");
            msg.exec();
            return QString{};
        }
        return parser::parserImage(image, suffix);
    }
    return info;
}
