#include <QApplication>
#include <QSplashScreen>
#include <QTimer>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QPixmap pixmap(":/images/rfsw.png");
    QPixmap scaledPixmap = pixmap.scaled(600, 600, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QSplashScreen splash(scaledPixmap);
    splash.show();
    int time = 3000;
    QTimer::singleShot(time, &splash, &QSplashScreen::close);
    MainWindow w;
    QTimer::singleShot(time, &w, &MainWindow::showMaximized);
    return a.exec();
}
