#include <QTableView>
#include <QSqlQueryModel>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QFileDialog>

double overtimeHours;
void exportCSV()
{
    QString fileName = QFileDialog::getSaveFileName(nullptr, "Save CSV", "", "CSV Files (*.csv)");

    if (fileName.isEmpty()) {
        return;
    }
//Emp(nompren,adresse_email,mdp,cin_emp,num_tel,date_derecru,departement,poste,salaire,hfixe,hsupp);
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * from EMPLOYEE");
    // [Collect model data to QString]

    QString textData = "CIN,NOM, EMAIL,NUM TEL, DEPARTEMENT,MOT_DE_PASSE, POSTE,DATE RECRUTEMENT,SALAIRE,HEURES_FIXES,HEURES_SUPPLEMENTAIRES,PRIME \n";
    int rows = model->rowCount();
    int columns = model->columnCount()+1;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {


            double overtimepay=0.0;
            textData += model->data(model->index(i,j)).toString();
               // textData += ", ";      // for .csv file format
                if (j==10)
                {
                    overtimeHours = model->data(model->index(i, j)).toDouble();
                    overtimepay = overtimeHours * 10.5;

                }
                if (j==11)
                {
                 //   overtimeHours = model->data(model->index(i, j)).toDouble();
                     overtimepay = overtimeHours * 10.5;
                    textData +=QString::number(overtimepay);


                }
                textData += ", ";


        }
        textData += "\n"; // (optional: for new line segmentation)

    }


    // .csv
    QFile csvFile(fileName);
    if(csvFile.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        QTextStream out(&csvFile);
        out << textData;
        csvFile.close();
    }
}

