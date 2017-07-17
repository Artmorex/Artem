#include <QApplication>
#include <Widget.h>
#include <Singleton.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Game& single = Game::Instance();
    single.Run();

    return a.exec();
}
