#include <time.h>
#include <fstream>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <vector>
#include <math.h>
#include <string>

#include "MedicalImage.h"

#include <dirent.h>
#include <QDirIterator>

using namespace std;
using namespace cv;

#define LEVEL_LUNG 50
#define WIDTH_LUNG 80

vector <IplImage*> img3d;
vector <float> indexZ;
int total_de_imagens;

vector<string> Carregar_Diretorios(string path, string fileExt)
{
    vector<std::string> filenames;

    QDirIterator dirIt(path.c_str(),QDirIterator::Subdirectories);
    while (dirIt.hasNext()) {
        dirIt.next();
        if (QFileInfo(dirIt.filePath()).isFile())
            if (QFileInfo(dirIt.filePath()).suffix() == fileExt.c_str()) {
                filenames.push_back( dirIt.fileName().toUtf8().constData() );
            }
    }

    return filenames;
}

/*
vector<string> Carregar_Diretorios(string diretorio, string extensao)
{
    vector <string> vetor_diretorios_imagens_dcom;
    char* filename;

    WIN32_FIND_DATA FindData;
    HANDLE hFind;

    char directory[512];
    char finalDir[512];
    sprintf(directory, "%s", diretorio.c_str());

    strcat(directory, "*.");
    strcat(directory, extensao.c_str());

    hFind = FindFirstFile(directory, &FindData);
    filename = FindData.cFileName;
    sprintf(finalDir, "%s%s", diretorio.c_str(), filename);
    vetor_diretorios_imagens_dcom.push_back(finalDir);

    while (FindNextFile(hFind, &FindData))
    {
        filename = FindData.cFileName;

        sprintf(finalDir, "%s%s", diretorio.c_str(), filename);
        vetor_diretorios_imagens_dcom.push_back(finalDir);
    }

    return vetor_diretorios_imagens_dcom ;
}
*/
void ajustar_imagem_para_8_bits(IplImage* imagem , IplImage* imagem_dst , int level, int width)
{
    int i, pix;
    for(i = 0; i < imagem->width * imagem->height; i++)
    {
        pix = (int)cvGetReal1D(imagem, i);
        pix = (pix - (level-width/2))*255/width;
        cvSet1D(imagem_dst, i, CV_RGB(pix, pix, pix));
    }
}

void add2DImgFromArray(int* img, int width, int height)
{
    IplImage* aux = cvCreateImage(cvSize(width, height), IPL_DEPTH_16S, 1);

    int i, j, pix;
    for(i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            pix = img[i*width+j];
            cvSetReal2D(aux, i, j, pix);
        }

    }
    img3d.push_back(aux);
}

void CarregarImagens(string local , string extencao){

    MedicalImage dcm;
    vector <string> vetor_enderecos_dcom = Carregar_Diretorios(local ,extencao);
    string dir("/home/walisson/Documentos/PROGRAMAS QT/dcm_to_jpg/zz/");

    //TOTAL DE IMAGENS
    total_de_imagens = (int)vetor_enderecos_dcom.size();
    printf("\n>>> TOTAL DE IMG : %d ( %d )\n\n",total_de_imagens , (int)vetor_enderecos_dcom.size()) ;

    //CARREGANDO
    //cout << dcm.OpenDicomFile(vetor_enderecos_dcom[0].c_str()) << endl;
    cout << vetor_enderecos_dcom[0].c_str() << endl;
    for(int i = 0 ; i < total_de_imagens ; i++){
        vetor_enderecos_dcom[i] = dir + vetor_enderecos_dcom[i];
        cout << vetor_enderecos_dcom[i] << endl;
        if(dcm.OpenDicomFile(vetor_enderecos_dcom[i].c_str())){
            cout << "Pronto!\n";
            indexZ.push_back ( (float) dcm.SliceLocation() );
            add2DImgFromArray(dcm.loadImage(), dcm.Columns(), dcm.Rows());
            //printf(">>> Carregando Imagens... %d\r" , i+1);
            cout << "Carregando Imagens... " << i + 1 << "\n";
        }
    }
    printf("\n");
}

void salvarImagens(int id, IplImage* imagem, String local, String extencao) {
    char arquivo[512];
    sprintf(arquivo, "%s%s%d%s", local.c_str(), "imagem", id, extencao.c_str());
    cvSaveImage(arquivo, imagem);
}

void mostra_dicom (IplImage* imagem, int id, string local) {
    // Cria espaços de imagens vazias:
    IplImage* imagem_dcom_ajustada_8_bits = cvCreateImage(cvGetSize(imagem), 8, 3);
    IplImage* imagem_gray = cvCreateImage(cvGetSize( imagem_dcom_ajustada_8_bits ) , IPL_DEPTH_8U , 1);

    // AJUSTA IMAGEM PARA 8 BITS
    ajustar_imagem_para_8_bits(imagem, imagem_dcom_ajustada_8_bits, LEVEL_LUNG, WIDTH_LUNG);

    // CONVERTE PARA TONS DE CINZA
    cvCvtColor( imagem_dcom_ajustada_8_bits, imagem_gray, CV_RGB2GRAY);

    // EXIBE IMAGEM
    cout<<"\nImagem "<<id<<" de "<<total_de_imagens;
    cvNamedWindow("IMAGEM", CV_WINDOW_AUTOSIZE);
    cvShowImage("IMAGEM", imagem_gray);

    // SALVA A IMAGEM_GRAY
    char arquivo[512];
    sprintf(arquivo, "%s%s%d%s", local.c_str(), "imagem", id, ".bmp");
    cvSaveImage(arquivo, imagem_gray);
    cvWaitKey(0);
}

int main(){
    string dir("/home/walisson/Documentos/PROGRAMAS QT/dcm_to_jpg/zz/");
    CarregarImagens("/home/walisson/Documentos/PROGRAMAS QT/dcm_to_jpg/zz/", "dcm");

    /*IplImage* img;
    img = cvLoadImage( "C:\\img\\cer.jpg", CV_LOAD_IMAGE_COLOR);

    if (!img)
    {
        cout<<"Nao foi possivel abrir a imagem\n";
        system("pause");
        return -1;
    }*/

    for(int i = 0; i < total_de_imagens; i++){
        mostra_dicom(img3d[i], i, dir + "save/");
        //salvarImagens(i, img3d[i], "/home/walisson/Documentos/PROGRAMAS QT/dcm_to_jpg/zz/save/", ".bmp");
    }

    cout << "Pronto!\n";

    cvWaitKey(0);
    //system("pause");

    return 1;
}
