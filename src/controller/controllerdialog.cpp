#include "controllerdialog.h"

ControllerDialog::ControllerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ControllerDialog)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Window);

    on_createFastTableButton_clicked();
}

ControllerDialog::~ControllerDialog()
{
    delete ui;
}

void ControllerDialog::on_deleteButton_clicked()
{
    delete mFastTableWidget;

    ui->mainStackedWidget->setCurrentIndex(1);
}

void ControllerDialog::on_rowCountSpinBox_valueChanged(int value)
{
    mFastTableWidget->setRowCount(value);
}

void ControllerDialog::on_columnCountSpinBox_valueChanged(int value)
{
    mFastTableWidget->setColumnCount(value);
}

void ControllerDialog::on_horizontalHeaderRowCountSpinBox_valueChanged(int value)
{
    mFastTableWidget->horizontalHeader_SetRowCount(value);
}

void ControllerDialog::on_verticalHeaderColumnCountSpinBox_valueChanged(int value)
{
    mFastTableWidget->verticalHeader_SetColumnCount(value);
}

void ControllerDialog::on_addRowButton_clicked()
{
    mFastTableWidget->addRow();

    disconnect(ui->rowCountSpinBox, SIGNAL(valueChanged(int)), this, SLOT(on_rowCountSpinBox_valueChanged(int)));
    ui->rowCountSpinBox->setValue(mFastTableWidget->rowCount());
    connect(ui->rowCountSpinBox, SIGNAL(valueChanged(int)), this, SLOT(on_rowCountSpinBox_valueChanged(int)));
}

void ControllerDialog::on_insertRowButton_clicked()
{
    QInputDialog dialog(this);

    dialog.setWindowTitle("Input row");
    dialog.setIntMinimum(0);
    dialog.setIntMaximum(mFastTableWidget->rowCount());
    dialog.setIntValue(0);

    if (dialog.exec())
    {
        mFastTableWidget->insertRow(dialog.intValue());

        disconnect(ui->rowCountSpinBox, SIGNAL(valueChanged(int)), this, SLOT(on_rowCountSpinBox_valueChanged(int)));
        ui->rowCountSpinBox->setValue(mFastTableWidget->rowCount());
        connect(ui->rowCountSpinBox, SIGNAL(valueChanged(int)), this, SLOT(on_rowCountSpinBox_valueChanged(int)));
    }
}

void ControllerDialog::on_deleteRowButton_clicked()
{
    if (mFastTableWidget->rowCount()>0)
    {
        QInputDialog dialog(this);

        dialog.setWindowTitle("Delete row");
        dialog.setIntMinimum(0);
        dialog.setIntMaximum(mFastTableWidget->rowCount()-1);
        dialog.setIntValue(0);

        if (dialog.exec())
        {
            mFastTableWidget->deleteRow(dialog.intValue());

            disconnect(ui->rowCountSpinBox, SIGNAL(valueChanged(int)), this, SLOT(on_rowCountSpinBox_valueChanged(int)));
            ui->rowCountSpinBox->setValue(mFastTableWidget->rowCount());
            connect(ui->rowCountSpinBox, SIGNAL(valueChanged(int)), this, SLOT(on_rowCountSpinBox_valueChanged(int)));
        }
    }
}

void ControllerDialog::on_addColumnButton_clicked()
{
    mFastTableWidget->addColumn();

    disconnect(ui->columnCountSpinBox, SIGNAL(valueChanged(int)), this, SLOT(on_columnCountSpinBox_valueChanged(int)));
    ui->columnCountSpinBox->setValue(mFastTableWidget->columnCount());
    connect(ui->columnCountSpinBox, SIGNAL(valueChanged(int)), this, SLOT(on_columnCountSpinBox_valueChanged(int)));
}

void ControllerDialog::on_insertColumnButton_clicked()
{
    QInputDialog dialog(this);

    dialog.setWindowTitle("Input column");
    dialog.setIntMinimum(0);
    dialog.setIntMaximum(mFastTableWidget->columnCount());
    dialog.setIntValue(0);

    if (dialog.exec())
    {
        mFastTableWidget->insertColumn(dialog.intValue());

        disconnect(ui->columnCountSpinBox, SIGNAL(valueChanged(int)), this, SLOT(on_columnCountSpinBox_valueChanged(int)));
        ui->columnCountSpinBox->setValue(mFastTableWidget->columnCount());
        connect(ui->columnCountSpinBox, SIGNAL(valueChanged(int)), this, SLOT(on_columnCountSpinBox_valueChanged(int)));
    }
}

void ControllerDialog::on_deleteColumnButton_clicked()
{
    if (mFastTableWidget->columnCount()>0)
    {
        QInputDialog dialog(this);

        dialog.setWindowTitle("Delete column");
        dialog.setIntMinimum(0);
        dialog.setIntMaximum(mFastTableWidget->columnCount()-1);
        dialog.setIntValue(0);

        if (dialog.exec())
        {
            mFastTableWidget->deleteColumn(dialog.intValue());

            disconnect(ui->columnCountSpinBox, SIGNAL(valueChanged(int)), this, SLOT(on_columnCountSpinBox_valueChanged(int)));
            ui->columnCountSpinBox->setValue(mFastTableWidget->columnCount());
            connect(ui->columnCountSpinBox, SIGNAL(valueChanged(int)), this, SLOT(on_columnCountSpinBox_valueChanged(int)));
        }
    }
}

void ControllerDialog::on_addHeaderRowButton_clicked()
{
    mFastTableWidget->horizontalHeader_AddRow();

    disconnect(ui->horizontalHeaderRowCountSpinBox, SIGNAL(valueChanged(int)), this, SLOT(on_horizontalHeaderRowCountSpinBox_valueChanged(int)));
    ui->horizontalHeaderRowCountSpinBox->setValue(mFastTableWidget->horizontalHeader_RowCount());
    connect(ui->horizontalHeaderRowCountSpinBox, SIGNAL(valueChanged(int)), this, SLOT(on_horizontalHeaderRowCountSpinBox_valueChanged(int)));
}

void ControllerDialog::on_insertHeaderRowButton_clicked()
{
    QInputDialog dialog(this);

    dialog.setWindowTitle("Input row");
    dialog.setIntMinimum(0);
    dialog.setIntMaximum(mFastTableWidget->horizontalHeader_RowCount());
    dialog.setIntValue(0);

    if (dialog.exec())
    {
        mFastTableWidget->horizontalHeader_InsertRow(dialog.intValue());

        disconnect(ui->horizontalHeaderRowCountSpinBox, SIGNAL(valueChanged(int)), this, SLOT(on_horizontalHeaderRowCountSpinBox_valueChanged(int)));
        ui->horizontalHeaderRowCountSpinBox->setValue(mFastTableWidget->horizontalHeader_RowCount());
        connect(ui->horizontalHeaderRowCountSpinBox, SIGNAL(valueChanged(int)), this, SLOT(on_horizontalHeaderRowCountSpinBox_valueChanged(int)));
    }
}

void ControllerDialog::on_deleteHeaderRowButton_clicked()
{
    if (mFastTableWidget->horizontalHeader_RowCount()>0)
    {
        QInputDialog dialog(this);

        dialog.setWindowTitle("Delete row");
        dialog.setIntMinimum(0);
        dialog.setIntMaximum(mFastTableWidget->horizontalHeader_RowCount()-1);
        dialog.setIntValue(0);

        if (dialog.exec())
        {
            mFastTableWidget->horizontalHeader_DeleteRow(dialog.intValue());

            disconnect(ui->horizontalHeaderRowCountSpinBox, SIGNAL(valueChanged(int)), this, SLOT(on_horizontalHeaderRowCountSpinBox_valueChanged(int)));
            ui->horizontalHeaderRowCountSpinBox->setValue(mFastTableWidget->horizontalHeader_RowCount());
            connect(ui->horizontalHeaderRowCountSpinBox, SIGNAL(valueChanged(int)), this, SLOT(on_horizontalHeaderRowCountSpinBox_valueChanged(int)));
        }
    }
}

void ControllerDialog::on_addHeaderColumnButton_clicked()
{
    mFastTableWidget->verticalHeader_AddColumn();

    disconnect(ui->verticalHeaderColumnCountSpinBox, SIGNAL(valueChanged(int)), this, SLOT(on_verticalHeaderColumnCountSpinBox_valueChanged(int)));
    ui->verticalHeaderColumnCountSpinBox->setValue(mFastTableWidget->verticalHeader_ColumnCount());
    connect(ui->verticalHeaderColumnCountSpinBox, SIGNAL(valueChanged(int)), this, SLOT(on_verticalHeaderColumnCountSpinBox_valueChanged(int)));
}

void ControllerDialog::on_insertHeaderColumnButton_clicked()
{
    QInputDialog dialog(this);

    dialog.setWindowTitle("Input column");
    dialog.setIntMinimum(0);
    dialog.setIntMaximum(mFastTableWidget->verticalHeader_ColumnCount());
    dialog.setIntValue(0);

    if (dialog.exec())
    {
        mFastTableWidget->verticalHeader_InsertColumn(dialog.intValue());

        disconnect(ui->verticalHeaderColumnCountSpinBox, SIGNAL(valueChanged(int)), this, SLOT(on_verticalHeaderColumnCountSpinBox_valueChanged(int)));
        ui->verticalHeaderColumnCountSpinBox->setValue(mFastTableWidget->verticalHeader_ColumnCount());
        connect(ui->verticalHeaderColumnCountSpinBox, SIGNAL(valueChanged(int)), this, SLOT(on_verticalHeaderColumnCountSpinBox_valueChanged(int)));
    }
}

void ControllerDialog::on_deleteHeaderColumnButton_clicked()
{
    if (mFastTableWidget->verticalHeader_ColumnCount()>0)
    {
        QInputDialog dialog(this);

        dialog.setWindowTitle("Delete column");
        dialog.setIntMinimum(0);
        dialog.setIntMaximum(mFastTableWidget->verticalHeader_ColumnCount()-1);
        dialog.setIntValue(0);

        if (dialog.exec())
        {
            mFastTableWidget->verticalHeader_DeleteColumn(dialog.intValue());

            disconnect(ui->verticalHeaderColumnCountSpinBox, SIGNAL(valueChanged(int)), this, SLOT(on_verticalHeaderColumnCountSpinBox_valueChanged(int)));
            ui->verticalHeaderColumnCountSpinBox->setValue(mFastTableWidget->verticalHeader_ColumnCount());
            connect(ui->verticalHeaderColumnCountSpinBox, SIGNAL(valueChanged(int)), this, SLOT(on_verticalHeaderColumnCountSpinBox_valueChanged(int)));
        }
    }
}

void ControllerDialog::on_clearButton_clicked()
{
    mFastTableWidget->clear();

    disconnect(ui->rowCountSpinBox, SIGNAL(valueChanged(int)), this, SLOT(on_rowCountSpinBox_valueChanged(int)));
    disconnect(ui->columnCountSpinBox, SIGNAL(valueChanged(int)), this, SLOT(on_columnCountSpinBox_valueChanged(int)));
    disconnect(ui->horizontalHeaderRowCountSpinBox, SIGNAL(valueChanged(int)), this, SLOT(on_horizontalHeaderRowCountSpinBox_valueChanged(int)));
    disconnect(ui->verticalHeaderColumnCountSpinBox, SIGNAL(valueChanged(int)), this, SLOT(on_verticalHeaderColumnCountSpinBox_valueChanged(int)));
    ui->rowCountSpinBox->setValue(mFastTableWidget->rowCount());
    ui->columnCountSpinBox->setValue(mFastTableWidget->columnCount());
    ui->horizontalHeaderRowCountSpinBox->setValue(mFastTableWidget->horizontalHeader_RowCount());
    ui->verticalHeaderColumnCountSpinBox->setValue(mFastTableWidget->verticalHeader_ColumnCount());
    connect(ui->rowCountSpinBox, SIGNAL(valueChanged(int)), this, SLOT(on_rowCountSpinBox_valueChanged(int)));
    connect(ui->columnCountSpinBox, SIGNAL(valueChanged(int)), this, SLOT(on_columnCountSpinBox_valueChanged(int)));
    connect(ui->horizontalHeaderRowCountSpinBox, SIGNAL(valueChanged(int)), this, SLOT(on_horizontalHeaderRowCountSpinBox_valueChanged(int)));
    connect(ui->verticalHeaderColumnCountSpinBox, SIGNAL(valueChanged(int)), this, SLOT(on_verticalHeaderColumnCountSpinBox_valueChanged(int)));
}

void ControllerDialog::on_selectRowButton_clicked()
{
    if (mFastTableWidget->rowCount()>0)
    {
        QInputDialog dialog(this);

        dialog.setWindowTitle("Select row");
        dialog.setIntMinimum(0);
        dialog.setIntMaximum(mFastTableWidget->rowCount()-1);
        dialog.setIntValue(0);

        if (dialog.exec())
        {
            mFastTableWidget->selectRow(dialog.intValue());
        }
    }
}

void ControllerDialog::on_unselectRowButton_clicked()
{
    if (mFastTableWidget->rowCount()>0)
    {
        QInputDialog dialog(this);

        dialog.setWindowTitle("Unselect row");
        dialog.setIntMinimum(0);
        dialog.setIntMaximum(mFastTableWidget->rowCount()-1);
        dialog.setIntValue(0);

        if (dialog.exec())
        {
            mFastTableWidget->unselectRow(dialog.intValue());
        }
    }

}

void ControllerDialog::on_selectColumnButton_clicked()
{
    if (mFastTableWidget->columnCount()>0)
    {
        QInputDialog dialog(this);

        dialog.setWindowTitle("Select column");
        dialog.setIntMinimum(0);
        dialog.setIntMaximum(mFastTableWidget->columnCount()-1);
        dialog.setIntValue(0);

        if (dialog.exec())
        {
            mFastTableWidget->selectColumn(dialog.intValue());
        }
    }
}

void ControllerDialog::on_unselectColumnButton_clicked()
{
    if (mFastTableWidget->columnCount()>0)
    {
        QInputDialog dialog(this);

        dialog.setWindowTitle("Unselect column");
        dialog.setIntMinimum(0);
        dialog.setIntMaximum(mFastTableWidget->columnCount()-1);
        dialog.setIntValue(0);

        if (dialog.exec())
        {
            mFastTableWidget->unselectColumn(dialog.intValue());
        }
    }
}

void ControllerDialog::on_selectAllButton_clicked()
{
    mFastTableWidget->selectAll();
}

void ControllerDialog::on_unselectAllButton_clicked()
{
    mFastTableWidget->unselectAll();
}

void ControllerDialog::on_defaultBackgroundButton_clicked()
{
    QColorDialog dialog(this);

    dialog.setWindowTitle("Default background color");
    dialog.setCurrentColor(mFastTableWidget->defaultBackgroundBrush().color());

    if (dialog.exec())
    {
        mFastTableWidget->setDefaultBackgroundBrush(QBrush(dialog.selectedColor()));
    }
}

void ControllerDialog::on_defaultForegroundButton_clicked()
{
    QColorDialog dialog(this);

    dialog.setWindowTitle("Default foreground color");
    dialog.setCurrentColor(mFastTableWidget->defaultForegroundColor());

    if (dialog.exec())
    {
        mFastTableWidget->setDefaultForegroundColor(dialog.selectedColor());
    }
}

void ControllerDialog::on_gridColorButton_clicked()
{
    QColorDialog dialog(this);

    dialog.setWindowTitle("Grid color");
    dialog.setCurrentColor(mFastTableWidget->gridColor());

    if (dialog.exec())
    {
        mFastTableWidget->setGridColor(dialog.selectedColor());
    }
}

void ControllerDialog::on_horizontalDefaultBackgroundButton_clicked()
{
    QColorDialog dialog(this);

    dialog.setWindowTitle("Default background color");
    dialog.setCurrentColor(mFastTableWidget->horizontalHeader_DefaultBackgroundBrush().color());

    if (dialog.exec())
    {
        mFastTableWidget->horizontalHeader_SetDefaultBackgroundBrush(QBrush(dialog.selectedColor()));
    }
}

void ControllerDialog::on_horizontalDefaultForegroundButton_clicked()
{
    QColorDialog dialog(this);

    dialog.setWindowTitle("Default foreground color");
    dialog.setCurrentColor(mFastTableWidget->horizontalHeader_DefaultForegroundColor());

    if (dialog.exec())
    {
        mFastTableWidget->horizontalHeader_SetDefaultForegroundColor(dialog.selectedColor());
    }
}

void ControllerDialog::on_horizontalGridColorButton_clicked()
{
    QColorDialog dialog(this);

    dialog.setWindowTitle("Grid color");
    dialog.setCurrentColor(mFastTableWidget->horizontalHeader_GridColor());

    if (dialog.exec())
    {
        mFastTableWidget->horizontalHeader_SetGridColor(dialog.selectedColor());
    }
}

void ControllerDialog::on_verticalDefaultBackgroundButton_clicked()
{
    QColorDialog dialog(this);

    dialog.setWindowTitle("Default background color");
    dialog.setCurrentColor(mFastTableWidget->verticalHeader_DefaultBackgroundBrush().color());

    if (dialog.exec())
    {
        mFastTableWidget->verticalHeader_SetDefaultBackgroundBrush(QBrush(dialog.selectedColor()));
    }
}

void ControllerDialog::on_verticalDefaultForegroundButton_clicked()
{
    QColorDialog dialog(this);

    dialog.setWindowTitle("Default foreground color");
    dialog.setCurrentColor(mFastTableWidget->verticalHeader_DefaultForegroundColor());

    if (dialog.exec())
    {
        mFastTableWidget->verticalHeader_SetDefaultForegroundColor(dialog.selectedColor());
    }
}

void ControllerDialog::on_verticalGridColorButton_clicked()
{
    QColorDialog dialog(this);

    dialog.setWindowTitle("Grid color");
    dialog.setCurrentColor(mFastTableWidget->verticalHeader_GridColor());

    if (dialog.exec())
    {
        mFastTableWidget->verticalHeader_SetGridColor(dialog.selectedColor());
    }
}

void ControllerDialog::on_selectionColorButton_clicked()
{
    QColorDialog dialog(this);

    dialog.setWindowTitle("Selection color");
    dialog.setCurrentColor(mFastTableWidget->selectionBrush().color());

    if (dialog.exec())
    {
        mFastTableWidget->setSelectionBrush(QBrush(dialog.selectedColor()));
    }
}

void ControllerDialog::on_selectionTextColorButton_clicked()
{
    QColorDialog dialog(this);

    dialog.setWindowTitle("Selection text color");
    dialog.setCurrentColor(mFastTableWidget->selectionTextColor());

    if (dialog.exec())
    {
        mFastTableWidget->setSelectionTextColor(dialog.selectedColor());
    }
}

void ControllerDialog::on_defaultWidthSpinBox_valueChanged(int value)
{
    mFastTableWidget->setDefaultWidth(value);
}

void ControllerDialog::on_defaultHeightSpinBox_valueChanged(int value)
{
    mFastTableWidget->setDefaultHeight(value);
}

void ControllerDialog::on_columnWidthButton_clicked()
{
    if (mFastTableWidget->columnCount()>0)
    {
        QInputDialog dialog(this);

        dialog.setWindowTitle("Select column");
        dialog.setIntMinimum(0);
        dialog.setIntMaximum(mFastTableWidget->columnCount()-1);
        dialog.setIntValue(0);

        if (dialog.exec())
        {
            QInputDialog dialog2(this);

            dialog2.setWindowTitle("Input width");
            dialog2.setIntMinimum(0);
            dialog2.setIntMaximum(32767);
            dialog2.setIntValue(mFastTableWidget->columnWidth(dialog.intValue()));

            if (dialog2.exec())
            {
                mFastTableWidget->setColumnWidth(dialog.intValue(), dialog2.intValue());
            }
        }
    }
}

void ControllerDialog::on_rowHeightButton_clicked()
{
    if (mFastTableWidget->rowCount()>0)
    {
        QInputDialog dialog(this);

        dialog.setWindowTitle("Select row");
        dialog.setIntMinimum(0);
        dialog.setIntMaximum(mFastTableWidget->rowCount()-1);
        dialog.setIntValue(0);

        if (dialog.exec())
        {
            QInputDialog dialog2(this);

            dialog2.setWindowTitle("Input height");
            dialog2.setIntMinimum(0);
            dialog2.setIntMaximum(32767);
            dialog2.setIntValue(mFastTableWidget->rowHeight(dialog.intValue()));

            if (dialog2.exec())
            {
                mFastTableWidget->setRowHeight(dialog.intValue(), dialog2.intValue());
            }
        }
    }
}

void ControllerDialog::on_headerColumnWidthButton_clicked()
{
    if (mFastTableWidget->verticalHeader_ColumnCount()>0)
    {
        QInputDialog dialog(this);

        dialog.setWindowTitle("Select column");
        dialog.setIntMinimum(0);
        dialog.setIntMaximum(mFastTableWidget->verticalHeader_ColumnCount()-1);
        dialog.setIntValue(0);

        if (dialog.exec())
        {
            QInputDialog dialog2(this);

            dialog2.setWindowTitle("Input width");
            dialog2.setIntMinimum(0);
            dialog2.setIntMaximum(32767);
            dialog2.setIntValue(mFastTableWidget->verticalHeader_ColumnWidth(dialog.intValue()));

            if (dialog2.exec())
            {
                mFastTableWidget->verticalHeader_SetColumnWidth(dialog.intValue(), dialog2.intValue());
            }
        }
    }
}

void ControllerDialog::on_headerRowHeightButton_clicked()
{
    if (mFastTableWidget->horizontalHeader_RowCount()>0)
    {
        QInputDialog dialog(this);

        dialog.setWindowTitle("Select row");
        dialog.setIntMinimum(0);
        dialog.setIntMaximum(mFastTableWidget->horizontalHeader_RowCount()-1);
        dialog.setIntValue(0);

        if (dialog.exec())
        {
            QInputDialog dialog2(this);

            dialog2.setWindowTitle("Input height");
            dialog2.setIntMinimum(0);
            dialog2.setIntMaximum(32767);
            dialog2.setIntValue(mFastTableWidget->horizontalHeader_RowHeight(dialog.intValue()));

            if (dialog2.exec())
            {
                mFastTableWidget->horizontalHeader_SetRowHeight(dialog.intValue(), dialog2.intValue());
            }
        }
    }
}

void ControllerDialog::on_textButton_clicked()
{
    if (mFastTableWidget->rowCount()>0 && mFastTableWidget->columnCount()>0)
    {
        QInputDialog dialog(this);

        dialog.setWindowTitle("Select row");
        dialog.setIntMinimum(0);
        dialog.setIntMaximum(mFastTableWidget->rowCount()-1);
        dialog.setIntValue(0);

        if (dialog.exec())
        {
            QInputDialog dialog2(this);

            dialog2.setWindowTitle("Select column");
            dialog2.setIntMinimum(0);
            dialog2.setIntMaximum(mFastTableWidget->columnCount()-1);
            dialog2.setIntValue(0);

            if (dialog2.exec())
            {
                QInputDialog dialog3(this);

                dialog3.setWindowTitle("Input text");
                dialog3.setTextValue(mFastTableWidget->text(dialog.intValue(), dialog2.intValue()));

                if (dialog3.exec())
                {
                    mFastTableWidget->setText(dialog.intValue(), dialog2.intValue(), dialog3.textValue());
                }
            }
        }
    }
}

void ControllerDialog::on_horizontalTextButton_clicked()
{
    if (mFastTableWidget->horizontalHeader_RowCount()>0 && mFastTableWidget->columnCount()>0)
    {
        QInputDialog dialog(this);

        dialog.setWindowTitle("Select row");
        dialog.setIntMinimum(0);
        dialog.setIntMaximum(mFastTableWidget->horizontalHeader_RowCount()-1);
        dialog.setIntValue(0);

        if (dialog.exec())
        {
            QInputDialog dialog2(this);

            dialog2.setWindowTitle("Select column");
            dialog2.setIntMinimum(0);
            dialog2.setIntMaximum(mFastTableWidget->columnCount()-1);
            dialog2.setIntValue(0);

            if (dialog2.exec())
            {
                QInputDialog dialog3(this);

                dialog3.setWindowTitle("Input text");
                dialog3.setTextValue(mFastTableWidget->horizontalHeader_Text(dialog.intValue(), dialog2.intValue()));

                if (dialog3.exec())
                {
                    mFastTableWidget->horizontalHeader_SetText(dialog.intValue(), dialog2.intValue(), dialog3.textValue());
                }
            }
        }
    }
}

void ControllerDialog::on_verticalTextButton_clicked()
{
    if (mFastTableWidget->rowCount()>0 && mFastTableWidget->verticalHeader_ColumnCount()>0)
    {
        QInputDialog dialog(this);

        dialog.setWindowTitle("Select row");
        dialog.setIntMinimum(0);
        dialog.setIntMaximum(mFastTableWidget->rowCount()-1);
        dialog.setIntValue(0);

        if (dialog.exec())
        {
            QInputDialog dialog2(this);

            dialog2.setWindowTitle("Select column");
            dialog2.setIntMinimum(0);
            dialog2.setIntMaximum(mFastTableWidget->verticalHeader_ColumnCount()-1);
            dialog2.setIntValue(0);

            if (dialog2.exec())
            {
                QInputDialog dialog3(this);

                dialog3.setWindowTitle("Input text");
                dialog3.setTextValue(mFastTableWidget->verticalHeader_Text(dialog.intValue(), dialog2.intValue()));

                if (dialog3.exec())
                {
                    mFastTableWidget->verticalHeader_SetText(dialog.intValue(), dialog2.intValue(), dialog3.textValue());
                }
            }
        }
    }
}

void ControllerDialog::on_cellSelectedButton_clicked()
{
    if (mFastTableWidget->rowCount()>0 && mFastTableWidget->columnCount()>0)
    {
        QInputDialog dialog(this);

        dialog.setWindowTitle("Select row");
        dialog.setIntMinimum(0);
        dialog.setIntMaximum(mFastTableWidget->rowCount()-1);
        dialog.setIntValue(0);

        if (dialog.exec())
        {
            QInputDialog dialog2(this);

            dialog2.setWindowTitle("Select column");
            dialog2.setIntMinimum(0);
            dialog2.setIntMaximum(mFastTableWidget->columnCount()-1);
            dialog2.setIntValue(0);

            if (dialog2.exec())
            {
                mFastTableWidget->setCellSelected(dialog.intValue(), dialog2.intValue(), !mFastTableWidget->cellSelected(dialog.intValue(), dialog2.intValue()));
            }
        }
    }
}

void ControllerDialog::on_backgroundButton_clicked()
{

}

void ControllerDialog::on_resetBackgroundButton_clicked()
{

}

void ControllerDialog::on_resetAllBackgroundButton_clicked()
{

}

void ControllerDialog::on_foregroundButton_clicked()
{

}

void ControllerDialog::on_resetForegroundButton_clicked()
{

}

void ControllerDialog::on_resetAllForegroundButton_clicked()
{

}

void ControllerDialog::on_cellFontButton_clicked()
{

}

void ControllerDialog::on_resetCellFontButton_clicked()
{

}

void ControllerDialog::on_resetAllCellFontButton_clicked()
{

}

void ControllerDialog::on_cellTextFlagsButton_clicked()
{

}

void ControllerDialog::on_resetCellTextFlagsButton_clicked()
{

}

void ControllerDialog::on_resetAllCellTextFlagsButton_clicked()
{

}

void ControllerDialog::on_horizontalBackgroundButton_clicked()
{

}

void ControllerDialog::on_horizontalResetBackgroundButton_clicked()
{

}

void ControllerDialog::on_horizontalResetAllBackgroundButton_clicked()
{

}

void ControllerDialog::on_horizontalForegroundButton_clicked()
{

}

void ControllerDialog::on_horizontalResetForegroundButton_clicked()
{

}

void ControllerDialog::on_horizontalResetAllForegroundButton_clicked()
{

}

void ControllerDialog::on_horizontalCellFontButton_clicked()
{

}

void ControllerDialog::on_horizontalResetCellFontButton_clicked()
{

}

void ControllerDialog::on_horizontalResetAllCellFontButton_clicked()
{

}

void ControllerDialog::on_horizontalCellTextFlagsButton_clicked()
{

}

void ControllerDialog::on_horizontalResetCellTextFlagsButton_clicked()
{

}

void ControllerDialog::on_horizontalResetAllCellTextFlagsButton_clicked()
{

}

void ControllerDialog::on_verticalBackgroundButton_clicked()
{

}

void ControllerDialog::on_verticalResetBackgroundButton_clicked()
{

}

void ControllerDialog::on_verticalResetAllBackgroundButton_clicked()
{

}

void ControllerDialog::on_verticalForegroundButton_clicked()
{

}

void ControllerDialog::on_verticalResetForegroundButton_clicked()
{

}

void ControllerDialog::on_verticalResetAllForegroundButton_clicked()
{

}

void ControllerDialog::on_verticalCellFontButton_clicked()
{

}

void ControllerDialog::on_verticalResetCellFontButton_clicked()
{

}

void ControllerDialog::on_verticalResetAllCellFontButton_clicked()
{

}

void ControllerDialog::on_verticalCellTextFlagsButton_clicked()
{

}

void ControllerDialog::on_verticalResetCellTextFlagsButton_clicked()
{

}

void ControllerDialog::on_verticalResetAllCellTextFlagsButton_clicked()
{

}

void ControllerDialog::on_mergeButton_clicked()
{
    if (mFastTableWidget->rowCount()>0 && mFastTableWidget->columnCount()>0)
    {
        QInputDialog dialog(this);

        dialog.setWindowTitle("Select row");
        dialog.setIntMinimum(0);
        dialog.setIntMaximum(mFastTableWidget->rowCount()-1);
        dialog.setIntValue(0);

        if (dialog.exec())
        {
            QInputDialog dialog2(this);

            dialog2.setWindowTitle("Select column");
            dialog2.setIntMinimum(0);
            dialog2.setIntMaximum(mFastTableWidget->columnCount()-1);
            dialog2.setIntValue(0);

            if (dialog2.exec())
            {
                QInputDialog dialog3(this);

                dialog3.setWindowTitle("Select row");
                dialog3.setIntMinimum(0);
                dialog3.setIntMaximum(mFastTableWidget->rowCount()-1);
                dialog3.setIntValue(0);

                if (dialog3.exec())
                {
                    QInputDialog dialog4(this);

                    dialog4.setWindowTitle("Select column");
                    dialog4.setIntMinimum(0);
                    dialog4.setIntMaximum(mFastTableWidget->columnCount()-1);
                    dialog4.setIntValue(0);

                    if (dialog4.exec())
                    {
                        int aLeft=qMin(dialog2.intValue(), dialog4.intValue());
                        int aTop=qMin(dialog.intValue(), dialog3.intValue());
                        int aRight=qMax(dialog2.intValue(), dialog4.intValue());
                        int aBottom=qMax(dialog.intValue(), dialog3.intValue());

                        ((FastTableWidget*)mFastTableWidget)->setSpan(aTop, aLeft, aBottom-aTop+1, aRight-aLeft+1);
                    }
                }
            }
        }
    }
}

void ControllerDialog::on_clearSpansButton_clicked()
{
    ((FastTableWidget*)mFastTableWidget)->clearSpans();
}

void ControllerDialog::on_horizontalMergeButton_clicked()
{
    if (mFastTableWidget->horizontalHeader_RowCount()>0 && mFastTableWidget->columnCount()>0)
    {
        QInputDialog dialog(this);

        dialog.setWindowTitle("Select row");
        dialog.setIntMinimum(0);
        dialog.setIntMaximum(mFastTableWidget->horizontalHeader_RowCount()-1);
        dialog.setIntValue(0);

        if (dialog.exec())
        {
            QInputDialog dialog2(this);

            dialog2.setWindowTitle("Select column");
            dialog2.setIntMinimum(0);
            dialog2.setIntMaximum(mFastTableWidget->columnCount()-1);
            dialog2.setIntValue(0);

            if (dialog2.exec())
            {
                QInputDialog dialog3(this);

                dialog3.setWindowTitle("Select row");
                dialog3.setIntMinimum(0);
                dialog3.setIntMaximum(mFastTableWidget->horizontalHeader_RowCount()-1);
                dialog3.setIntValue(0);

                if (dialog3.exec())
                {
                    QInputDialog dialog4(this);

                    dialog4.setWindowTitle("Select column");
                    dialog4.setIntMinimum(0);
                    dialog4.setIntMaximum(mFastTableWidget->columnCount()-1);
                    dialog4.setIntValue(0);

                    if (dialog4.exec())
                    {
                        int aLeft=qMin(dialog2.intValue(), dialog4.intValue());
                        int aTop=qMin(dialog.intValue(), dialog3.intValue());
                        int aRight=qMax(dialog2.intValue(), dialog4.intValue());
                        int aBottom=qMax(dialog.intValue(), dialog3.intValue());

                        ((FastTableWidget*)mFastTableWidget)->horizontalHeader_SetSpan(aTop, aLeft, aBottom-aTop+1, aRight-aLeft+1);
                    }
                }
            }
        }
    }
}

void ControllerDialog::on_horizontalClearSpansButton_clicked()
{
    ((FastTableWidget*)mFastTableWidget)->horizontalHeader_ClearSpans();
}

void ControllerDialog::on_verticalMergeButton_clicked()
{
    if (mFastTableWidget->rowCount()>0 && mFastTableWidget->verticalHeader_ColumnCount()>0)
    {
        QInputDialog dialog(this);

        dialog.setWindowTitle("Select row");
        dialog.setIntMinimum(0);
        dialog.setIntMaximum(mFastTableWidget->rowCount()-1);
        dialog.setIntValue(0);

        if (dialog.exec())
        {
            QInputDialog dialog2(this);

            dialog2.setWindowTitle("Select column");
            dialog2.setIntMinimum(0);
            dialog2.setIntMaximum(mFastTableWidget->verticalHeader_ColumnCount()-1);
            dialog2.setIntValue(0);

            if (dialog2.exec())
            {
                QInputDialog dialog3(this);

                dialog3.setWindowTitle("Select row");
                dialog3.setIntMinimum(0);
                dialog3.setIntMaximum(mFastTableWidget->rowCount()-1);
                dialog3.setIntValue(0);

                if (dialog3.exec())
                {
                    QInputDialog dialog4(this);

                    dialog4.setWindowTitle("Select column");
                    dialog4.setIntMinimum(0);
                    dialog4.setIntMaximum(mFastTableWidget->verticalHeader_ColumnCount()-1);
                    dialog4.setIntValue(0);

                    if (dialog4.exec())
                    {
                        int aLeft=qMin(dialog2.intValue(), dialog4.intValue());
                        int aTop=qMin(dialog.intValue(), dialog3.intValue());
                        int aRight=qMax(dialog2.intValue(), dialog4.intValue());
                        int aBottom=qMax(dialog.intValue(), dialog3.intValue());

                        ((FastTableWidget*)mFastTableWidget)->verticalHeader_SetSpan(aTop, aLeft, aBottom-aTop+1, aRight-aLeft+1);
                    }
                }
            }
        }
    }
}

void ControllerDialog::on_verticalClearSpansButton_clicked()
{
    ((FastTableWidget*)mFastTableWidget)->verticalHeader_ClearSpans();
}

void ControllerDialog::on_rowCountViewButton_clicked()
{
    ViewDialog dialog(((PublicCustomFastTable*)mFastTableWidget)->getRowCount(), this);
    dialog.exec();
}

void ControllerDialog::on_columnCountViewButton_clicked()
{
    ViewDialog dialog(((PublicCustomFastTable*)mFastTableWidget)->getColumnCount(), this);
    dialog.exec();
}

void ControllerDialog::on_horizontalHeaderRowCountViewButton_clicked()
{
    ViewDialog dialog(((PublicCustomFastTable*)mFastTableWidget)->horizontalHeader_GetRowCount(), this);
    dialog.exec();
}

void ControllerDialog::on_verticalHeaderColumnCountViewButton_clicked()
{
    ViewDialog dialog(((PublicCustomFastTable*)mFastTableWidget)->verticalHeader_GetColumnCount(), this);
    dialog.exec();
}

void ControllerDialog::on_defaultWidthViewButton_clicked()
{
    ViewDialog dialog(((PublicCustomFastTable*)mFastTableWidget)->defaultWidth(), this);
    dialog.exec();
}

void ControllerDialog::on_defaultHeightViewButton_clicked()
{
    ViewDialog dialog(((PublicCustomFastTable*)mFastTableWidget)->defaultHeight(), this);
    dialog.exec();
}

void ControllerDialog::on_columnWidthViewButton_clicked()
{
    ViewDialog dialog(((PublicCustomFastTable*)mFastTableWidget)->getColumnWidths(), false, this);
    dialog.exec();
}

void ControllerDialog::on_rowHeightViewButton_clicked()
{
    ViewDialog dialog(((PublicCustomFastTable*)mFastTableWidget)->getRowHeights(), true, this);
    dialog.exec();
}

void ControllerDialog::on_headerColumnWidthViewButton_clicked()
{
    ViewDialog dialog(((PublicCustomFastTable*)mFastTableWidget)->verticalHeader_GetColumnWidths(), false, this);
    dialog.exec();
}

void ControllerDialog::on_headerRowHeightViewButton_clicked()
{
    ViewDialog dialog(((PublicCustomFastTable*)mFastTableWidget)->horizontalHeader_GetRowHeights(), true, this);
    dialog.exec();
}

void ControllerDialog::on_totalWidthViewButton_clicked()
{
    ViewDialog dialog(((PublicCustomFastTable*)mFastTableWidget)->totalWidth(), this);
    dialog.exec();
}

void ControllerDialog::on_totalHeightViewButton_clicked()
{
    ViewDialog dialog(((PublicCustomFastTable*)mFastTableWidget)->totalHeight(), this);
    dialog.exec();
}

void ControllerDialog::on_headerTotalWidthViewButton_clicked()
{
    ViewDialog dialog(((PublicCustomFastTable*)mFastTableWidget)->verticalHeader_TotalWidth(), this);
    dialog.exec();
}

void ControllerDialog::on_headerTotalHeightViewButton_clicked()
{
    ViewDialog dialog(((PublicCustomFastTable*)mFastTableWidget)->horizontalHeader_TotalHeight(), this);
    dialog.exec();
}

void ControllerDialog::on_visibleRangesViewButton_clicked()
{
    QRect aRect=mFastTableWidget->visibleRange();

    QList<int> aList;

    aList.append(aRect.left());
    aList.append(aRect.top());
    aList.append(aRect.right());
    aList.append(aRect.bottom());

    ViewDialog dialog(&aList, false, this);
    dialog.exec();
}

void ControllerDialog::on_horizontalVisibleRangesViewButton_clicked()
{
    QRect aRect=mFastTableWidget->horizontalHeader_VisibleRange();

    QList<int> aList;

    aList.append(aRect.left());
    aList.append(aRect.top());
    aList.append(aRect.right());
    aList.append(aRect.bottom());

    ViewDialog dialog(&aList, false, this);
    dialog.exec();
}

void ControllerDialog::on_verticalVisibleRangesViewButton_clicked()
{
    QRect aRect=mFastTableWidget->verticalHeader_VisibleRange();

    QList<int> aList;

    aList.append(aRect.left());
    aList.append(aRect.top());
    aList.append(aRect.right());
    aList.append(aRect.bottom());

    ViewDialog dialog(&aList, false, this);
    dialog.exec();
}

void ControllerDialog::on_textViewButton_clicked()
{
    ViewDialog dialog(((PublicCustomFastTable*)mFastTableWidget)->getData(), this);
    dialog.exec();
}

void ControllerDialog::on_horizontalTextViewButton_clicked()
{
    ViewDialog dialog(((PublicCustomFastTable*)mFastTableWidget)->horizontalHeader_GetData(), this);
    dialog.exec();
}

void ControllerDialog::on_verticalTextViewButton_clicked()
{
    ViewDialog dialog(((PublicCustomFastTable*)mFastTableWidget)->verticalHeader_GetData(), this);
    dialog.exec();
}

void ControllerDialog::on_cellSelectedViewButton_clicked()
{
    ViewDialog dialog(((PublicCustomFastTable*)mFastTableWidget)->getSelectedCells(), this);
    dialog.exec();
}

void ControllerDialog::on_currentSelectionViewButton_clicked()
{
    QList<QList<int> > aList;

    QList<QPoint> *aSelection=((PublicCustomFastTable*)mFastTableWidget)->getCurSelection();

    for (int i=0; i<aSelection->length(); i++)
    {
        QList<int> aRow;

        aRow.append(aSelection->at(i).x());
        aRow.append(aSelection->at(i).y());

        aList.append(aRow);
    }

    ViewDialog dialog(&aList, this);
    dialog.exec();
}

void ControllerDialog::on_rowsSelectedViewButton_clicked()
{
    ViewDialog dialog(((PublicCustomFastTable*)mFastTableWidget)->verticalHeader_GetSelectedRows(), true, this);
    dialog.exec();
}

void ControllerDialog::on_columnsSelectedViewButton_clicked()
{
    ViewDialog dialog(((PublicCustomFastTable*)mFastTableWidget)->horizontalHeader_GetSelectedColumns(), false, this);
    dialog.exec();
}

void ControllerDialog::on_mergeParentViewButton_clicked()
{
    QList<QStringList> aList;

    for (int i=0; i<mFastTableWidget->rowCount(); i++)
    {
        QStringList aRow;

        for (int j=0; j<mFastTableWidget->columnCount(); j++)
        {
            QPoint aPoint=((FastTableWidget*)mFastTableWidget)->spanParent(i, j);

            aRow.append(QString::number(aPoint.y())+" "+QString::number(aPoint.x()));
        }

        aList.append(aRow);
    }

    ViewDialog dialog(&aList, this);
    dialog.exec();
}

void ControllerDialog::on_mergeXYViewButton_clicked()
{
    QList<QStringList> aList;

    for (int i=0; i<mFastTableWidget->rowCount(); i++)
    {
        QStringList aRow;

        for (int j=0; j<mFastTableWidget->columnCount(); j++)
        {
            aRow.append(QString::number(((FastTableWidget*)mFastTableWidget)->columnSpan(i, j))+" "+QString::number(((FastTableWidget*)mFastTableWidget)->rowSpan(i, j)));
        }

        aList.append(aRow);
    }

    ViewDialog dialog(&aList, this);
    dialog.exec();
}

void ControllerDialog::on_horizontalMergeParentViewButton_clicked()
{
    QList<QStringList> aList;

    for (int i=0; i<mFastTableWidget->horizontalHeader_RowCount(); i++)
    {
        QStringList aRow;

        for (int j=0; j<mFastTableWidget->columnCount(); j++)
        {
            QPoint aPoint=((FastTableWidget*)mFastTableWidget)->horizontalHeader_SpanParent(i, j);

            aRow.append(QString::number(aPoint.y())+" "+QString::number(aPoint.x()));
        }

        aList.append(aRow);
    }

    ViewDialog dialog(&aList, this);
    dialog.exec();
}

void ControllerDialog::on_horizontalMergeXYViewButton_clicked()
{
    QList<QStringList> aList;

    for (int i=0; i<mFastTableWidget->horizontalHeader_RowCount(); i++)
    {
        QStringList aRow;

        for (int j=0; j<mFastTableWidget->columnCount(); j++)
        {
            aRow.append(QString::number(((FastTableWidget*)mFastTableWidget)->horizontalHeader_ColumnSpan(i, j))+" "+QString::number(((FastTableWidget*)mFastTableWidget)->horizontalHeader_RowSpan(i, j)));
        }

        aList.append(aRow);
    }

    ViewDialog dialog(&aList, this);
    dialog.exec();
}

void ControllerDialog::on_verticalMergeParentViewButton_clicked()
{
    QList<QStringList> aList;

    for (int i=0; i<mFastTableWidget->rowCount(); i++)
    {
        QStringList aRow;

        for (int j=0; j<mFastTableWidget->verticalHeader_ColumnCount(); j++)
        {
            QPoint aPoint=((FastTableWidget*)mFastTableWidget)->verticalHeader_SpanParent(i, j);

            aRow.append(QString::number(aPoint.y())+" "+QString::number(aPoint.x()));
        }

        aList.append(aRow);
    }

    ViewDialog dialog(&aList, this);
    dialog.exec();
}

void ControllerDialog::on_verticalMergeXYViewButton_clicked()
{
    QList<QStringList> aList;

    for (int i=0; i<mFastTableWidget->rowCount(); i++)
    {
        QStringList aRow;

        for (int j=0; j<mFastTableWidget->verticalHeader_ColumnCount(); j++)
        {
            aRow.append(QString::number(((FastTableWidget*)mFastTableWidget)->verticalHeader_ColumnSpan(i, j))+" "+QString::number(((FastTableWidget*)mFastTableWidget)->verticalHeader_RowSpan(i, j)));
        }

        aList.append(aRow);
    }

    ViewDialog dialog(&aList, this);
    dialog.exec();
}

void ControllerDialog::on_createCustomTableButton_clicked()
{
    mFastTableWidget=new CustomFastTableWidget(this);
    ui->fastTableLayout->insertWidget(0, mFastTableWidget);

    ui->defaultWidthSpinBox->setValue(100);
    ui->defaultHeightSpinBox->setValue(30);

    ui->rowCountSpinBox->setValue(0);
    ui->columnCountSpinBox->setValue(0);
    ui->horizontalHeaderRowCountSpinBox->setValue(0);
    ui->verticalHeaderColumnCountSpinBox->setValue(0);

    ui->rowCountSpinBox->setValue(50);
    ui->columnCountSpinBox->setValue(20);
    ui->horizontalHeaderRowCountSpinBox->setValue(1);
    ui->verticalHeaderColumnCountSpinBox->setValue(1);

    for (int i=0; i<mFastTableWidget->rowCount(); ++i)
    {
        for (int j=0; j<mFastTableWidget->columnCount(); ++j)
        {
            mFastTableWidget->setText(i, j, "Hello, World");
        }
    }

    for (int i=0; i<mFastTableWidget->columnCount(); ++i)
    {
        mFastTableWidget->horizontalHeader_SetText(i, "Header");
    }

    ui->fastTableControlWidget->setVisible(false);

    ui->mainStackedWidget->setCurrentIndex(0);
}

void ControllerDialog::on_createFastTableButton_clicked()
{
    mFastTableWidget=new FastTableWidget(this);
    ui->fastTableLayout->insertWidget(0, mFastTableWidget);

    ui->defaultWidthSpinBox->setValue(100);
    ui->defaultHeightSpinBox->setValue(30);

    ui->rowCountSpinBox->setValue(0);
    ui->columnCountSpinBox->setValue(0);
    ui->horizontalHeaderRowCountSpinBox->setValue(0);
    ui->verticalHeaderColumnCountSpinBox->setValue(0);

    ui->rowCountSpinBox->setValue(50);
    ui->columnCountSpinBox->setValue(20);
    ui->horizontalHeaderRowCountSpinBox->setValue(1);
    ui->verticalHeaderColumnCountSpinBox->setValue(1);

    for (int i=0; i<mFastTableWidget->rowCount(); ++i)
    {
        for (int j=0; j<mFastTableWidget->columnCount(); ++j)
        {
            mFastTableWidget->setText(i, j, "Hello, World");
        }
    }

    for (int i=0; i<mFastTableWidget->columnCount(); ++i)
    {
        mFastTableWidget->horizontalHeader_SetText(i, "Header");
    }

    ui->fastTableControlWidget->setVisible(true);

    ui->mainStackedWidget->setCurrentIndex(0);
}
