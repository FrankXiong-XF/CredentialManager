#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    extern void Init();

	QApplication app(argc, argv);

    Init();

	return app.exec();
}
