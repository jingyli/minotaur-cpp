#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <memory>

#include <QMainWindow>
#include <QTextBrowser>
#include <QKeyEvent>

#include "../controller/controller.h"
#include "../controller/simulator.h"
#include "../script-engine/scriptengine.h"

#include "actuatorsetup.h"
#include "simulatorwindow.h"
#include "actionabout.h"
#include "scriptwindow.h"

#define DEFAULT_TITLE "minotaur"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0, const char* title = DEFAULT_TITLE);
    QTextEdit* getLogView();
    void keyPressEvent(QKeyEvent*);
    ~MainWindow();

public slots:
    void openActuatorSetup();
    void openScriptWindow();
    inline void switchToActuator() { switchControllerTo(Controller::Type::ACTUATOR); }
    inline void switchToSimulator() { switchControllerTo(Controller::Type::SIMULATOR); }
    void openActionAbout();

private slots:
    // Button click events
    void on_move_button_clicked();
    // Mouse events
    void mousePressEvent(QMouseEvent *event);

private:
    Ui::MainWindow *ui;
    ActuatorSetup *actuator_setup_window;
    ScriptWindow *script_window;
    SimulatorWindow *simulator_window;
    Controller::Type m_controller_type;
    ActionAbout *action_about_window;
    std::shared_ptr<Controller> m_controller;
    std::shared_ptr<Actuator> m_actuator;
    std::shared_ptr<Simulator> m_simulator;
    std::shared_ptr<ScriptEngine> m_script_engine;
	bool eventFilter(QObject*, QEvent*);
    void switchControllerTo(Controller::Type const type);
};

#endif // MAINWINDOW_H
