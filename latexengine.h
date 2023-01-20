/*
KoiralaSanskrit LICENSE:
THIS COPY OF LATEX_ENGINE IS BROUGHT WITHOUT ANY WARRANTY.
THIS LICENSE PROVIDES THE USER PRIVILEGES TO USE THIS PROGRAM
WITH THE CONDITION ONLY BEING THIS TEXT HAS TO BE REWRITTEN IN
ORIGINAL FORM BEFORE THE HEADERS OF THE SOURCE FILE IN
EACH MODIFIED OR UNMODIFIED COPY OF THIS CODE.
COPYRIGHT Koirala Sanskrit Animation Studios, 2023
*/
#ifndef LATEXENGINE_H
#define LATEXENGINE_H
#include <fstream>
#include <sstream>
#include <iostream>



struct LatexEngine {
    std::stringstream strstream;
    std::ofstream file;
    bool isInitialized = false;
    LatexEngine* initialize(std::string options = "11pt, a4paper", std::string docType = "article") {
        strstream << "\\documentclass[" << options << "]" << "{" << docType << "}\n";
        strstream << "\\usepackage{amsmath}\n";
        strstream << "\\usepackage{amssymb}\n";
        strstream << "\\usepackage{multicol}\n";
        strstream << "\\usepackage[top=0.5in, bottom=0.5in, left=0.5in, right=0.6in]{geometry}\n";
        strstream << "\\begin{document}\n";
        strstream << "\\small \\textit{077bct024: Darshan Koirala}\n\n";
        isInitialized = true;
        return this;
    }
    LatexEngine* begin(std::string env = "document") {
        strstream << "\\begin{" << env << "}\n";
        return this;
    }
    LatexEngine* end(std::string env = "document") {
        strstream << "\\end{" << env << "}\n";
        return this;
    }
    LatexEngine* usepackage(std::string package, std::string options = "") {
        if (options == "")
            strstream << "\\usepackage{" << package << "}\n";
        else
            strstream << "\\usepackage[" << options << "]{" << package << "}\n";
        return this;
    }
    LatexEngine* writeToFile() {
        file.open("myFile.tex");
        file << strstream.rdbuf();
        file.flush();
        file.close();
        return this;
    }
    LatexEngine* compile() {
        system("pdflatex myFile.tex --interaction=nonstopmode");
        system("wsl zathura myFile.pdf");
        return this; } };
#endif // LATEXENGINE_H
