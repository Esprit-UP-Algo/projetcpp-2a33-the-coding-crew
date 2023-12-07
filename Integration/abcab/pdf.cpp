#include "pdf.h"
#include <QPrinter>

void exportTableViewToPDF(QTableView* tableView)
{
    QString fileName = QFileDialog::getSaveFileName(nullptr, "Save PDF", "", "PDF Files (*.pdf)");

    if (fileName.isEmpty()) {
        return;
    }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    QTextCursor cursor(&doc);

    cursor.insertHtml("<h1>Liste des ressources</h1><br>");

    int rows = tableView->model()->rowCount();
    int columns = tableView->model()->columnCount();

    QTextTableFormat tableFormat;
    tableFormat.setCellPadding(4);
    tableFormat.setCellSpacing(0);
    QTextTable* textTable = cursor.insertTable(rows + 1, columns, tableFormat);

    // Insert column names as a header row
    for (int column = 0; column < columns; ++column) {
        QString columnName = tableView->model()->headerData(column, Qt::Horizontal).toString();
        QTextTableCell cell = textTable->cellAt(0, column);
        QTextCursor cellCursor = cell.firstCursorPosition();
        cellCursor.insertText(columnName);
    }

    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < columns; ++column) {
            QModelIndex index = tableView->model()->index(row, column);
            QString data = tableView->model()->data(index).toString();
            QTextTableCell cell = textTable->cellAt(row + 1, column);
            QTextCursor cellCursor = cell.firstCursorPosition();
            cellCursor.insertText(data);
        }
    }

    // Style the table with CSS
    QString tableStyle = "table { border-collapse: collapse; width: 100%; }";
    QString cellStyle = "td { border: 1px solid black; padding: 8px; }";
    QString headerCellStyle = "tr:first-child td { font-weight: bold; background-color: #ccc; }";
    cursor.insertHtml("<style>" + tableStyle + cellStyle + headerCellStyle + "</style>");

    doc.print(&printer);
}

