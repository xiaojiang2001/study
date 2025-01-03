#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "videoplayer.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event) override;


private slots:
    void slotGetOneFrame(QImage img);


private:
    Ui::MainWindow *ui;
    VideoPlayer *mplayer;
    QImage mImage;



};
#endif // MAINWINDOW_H
