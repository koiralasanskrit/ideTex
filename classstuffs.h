#ifndef CLASSSTUFFS_H
#define CLASSSTUFFS_H

#include "latexengine.h"

struct Matrix
{
    int m_rows = 0;
    int m_columns = 0;
    float* matrix{0};
    Matrix(int rows, int columns) {
        m_rows = rows;
        m_columns = columns;
        matrix = new float[m_rows*m_columns];
    }
    ~Matrix() {
        delete[] matrix;
    }
    float get(int i, int j) {
        return matrix[i * m_columns + j];
    }
    float& set(int i, int j) {
        return matrix[i * m_columns + j];
    }
    Matrix* print() {
        for (int i = 0; i < m_rows; i++) {
            for (int j = 0; j < m_columns; j++) {
                std::cout << get(i, j) << "\t" << std::flush;
            }
            std::cout << "\n" << std::flush;
        }
        std::cout << "\n\n" << std::flush;
        return this;
    }
    Matrix* printInLatex(LatexEngine* latex) {
        latex->strstream << "\n\\begin{flushleft}\n";
        latex->strstream << "$\\implies \\left(\\begin{array}{";
        for (int i = 0; i < m_columns; i++) {
            latex->strstream << "c";
        }
        latex->strstream << "}\n";
        for (int i = 0; i < m_rows; i++) {
            for (int j = 0; j < m_columns; j++) {
                latex->strstream << get(i, j);
                if (j < m_columns - 1) {
                    latex->strstream << "\t&\t";
                }
            }
            latex->strstream << "\\\\\n";
        }
        latex->strstream << "\\end{array}\\right)$\n";
        latex->strstream << "\\end{flushleft}\n\n";
        std::cout << "\n\n" << std::flush;
        return this;
    }
    Matrix* read() {
        for (int i = 0; i < m_rows; i++) {
            for (int j = 0; j < m_columns; j++) {
                std::cout << "Matrix(" << i + 1 << "," << j + 1 << "):" << std::flush;
                std::cin >> set(i, j);
            }
        }
        std::cout << "\n" << std::flush;;
        return this;
    }
    Matrix* makeIdentity() {
        for (int i = 0; i < m_rows; i++) {
            for (int j = 0; j < m_columns; j++) {
                if (i == j)
                    set(i, j) = 1;
                else
                    set(i, j) = 0;
            }
        }
        return this;
    }
    Matrix* inverse() {
        #define FOR_EACH_PIVOT_ROW(i) for(int i = 0; i < m_rows; i++)
        #define FOR_EACH_ROW(j) for(int j = 0; j < m_rows; j++)
        #define FOR_EACH_ROW_ELEMENT(k) for(int k = 0; k < m_columns; k++)

        float pivot = 0;
        Matrix *iden = (new Matrix(m_columns, m_rows))->makeIdentity();
        FOR_EACH_PIVOT_ROW(i) {
            FOR_EACH_ROW(j) {
                if (i != j) {
                    pivot = get(j, i) / get(i,i);
                    FOR_EACH_ROW_ELEMENT(k) {
                        set(j, k) = get(j, k) - pivot * get(i, k);
                        //For Augmented Matrix
                        iden->set(j, k) = iden->get(j, k) - pivot * iden->get(i, k);
                    }
                }
            }
        }
        FOR_EACH_ROW(i) {
            FOR_EACH_ROW_ELEMENT(j) {
                //For Augmented Matrix
                iden->set(i, j) = iden->get(i, j) / get(i, i);
            }
        }
        return iden;
    }
};


struct RK4 {

};

void matrixInversionAndRK4() {
    LatexEngine* latex = (new LatexEngine())->initialize("12pt, a4paper", "article");
    latex->begin("document");

    Matrix *mat = (new Matrix(3, 3))->read()->print();
    latex->strstream << "\nInput Matrix:";
    mat->printInLatex(latex);
    latex->strstream << "\n\nInverse Matrix:";
    Matrix *inv = mat->inverse()->print();
    inv->printInLatex(latex);
    delete inv;

    mat = (new Matrix(4, 4))->read()->print();
    latex->strstream << "\nInput Matrix:";
    mat->printInLatex(latex);
    latex->strstream << "\n\nInverse Matrix:";
    inv = mat->inverse()->print();
    inv->printInLatex(latex);
    delete inv;

    mat = (new Matrix(4, 4))->read()->print();
    latex->strstream << "\nInput Matrix:";
    mat->printInLatex(latex);
    latex->strstream << "\n\nInverse Matrix:";
    inv = mat->inverse()->print();
    inv->printInLatex(latex);
    delete inv;

    latex->end("document");
    latex->writeToFile()->compile();
}

#endif // CLASSSTUFFS_H
