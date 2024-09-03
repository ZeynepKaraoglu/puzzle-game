#ifndef ETIKET_H
#define ETIKET_H

#include <QWidget>
#include <QPixmap>
#include <QMouseEvent>
#include <QDebug>
#include <QString>
#include <QTimer>
#include <QUrl>
#include <QLabel>

class Etiket : public QLabel
{
    Q_OBJECT

public:
    explicit Etiket(QWidget *parent = nullptr);
      void setImagePath(const QString &path);


private:

      void dragEnterEvent(QDragEnterEvent *event);
      void dropEvent(QDropEvent *event);
      void mouseMoveEvent(QMouseEvent *event);

signals:


public slots:
};

#endif // ETIKET_H
