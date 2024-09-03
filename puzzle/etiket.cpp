#include "etiket.h"
#include <QMimeData>
#include <QDrag>

Etiket::Etiket(QWidget *parent)
    : QLabel(parent)
{
    setFrameShape(QFrame::Box);
    setScaledContents(true);
    setAcceptDrops(true);
}

void Etiket::setImagePath(const QString &path)
{
    QPixmap image(path);
   this->setPixmap(image.scaled(100, 100, Qt::KeepAspectRatio));
}

void Etiket::dragEnterEvent(QDragEnterEvent *event)
{
    event->accept();
}

void Etiket::dropEvent(QDropEvent *event)
{
    Etiket *gelen = qobject_cast<Etiket*>(event->source());
    if (gelen && gelen != this) {
        QImage birakilan(pixmap()->toImage());
        setPixmap(QPixmap::fromImage(gelen->pixmap()->toImage()));
        gelen->setPixmap(QPixmap::fromImage(birakilan));
        return;
    }


}

void Etiket::mouseMoveEvent(QMouseEvent *event)
{
    QMimeData *mdata = new QMimeData();
    mdata->setImageData(pixmap()->toImage());
    QDrag *suruklenen = new QDrag(this);
    suruklenen->setMimeData(mdata);
    suruklenen->setPixmap(mdata->imageData().value<QPixmap>());
    suruklenen->exec(Qt::MoveAction);
}

