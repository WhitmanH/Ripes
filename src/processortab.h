#ifndef PROCESSORTAB_H
#define PROCESSORTAB_H

#include <QTimer>
#include <QWidget>

#include "defines.h"
#include "pipeline.h"
#include "pipelinetable.h"
#include "pipelinetablemodel.h"

namespace Ui {
class ProcessorTab;
}

class InstructionModel;
class Parser;

class ProcessorTab : public QWidget {
    Q_OBJECT

public:
    explicit ProcessorTab(QWidget* parent = 0);
    ~ProcessorTab();

    void initRegWidget();
    void initInstructionView();

public slots:
    void restart();

private slots:
    void on_expandView_clicked();
    void on_displayValues_toggled(bool checked);
    void on_run_clicked();
    void on_reset_clicked();
    void on_step_clicked();
    void toggleTimer(bool state);
    void on_zoomIn_clicked();
    void on_zoomOut_clicked();
    void on_save_clicked();
    void setCurrentInstruction(int row);

    void on_table_clicked();

private:
    void handleEcall();

    Ui::ProcessorTab* m_ui;
    InstructionModel* m_instrModel;

    QTimer m_timer;

signals:
    void update();
    void appendToLog(QString string);
};

#endif  // PROCESSORTAB_H
