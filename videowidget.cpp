#include "videowidget.h"
#include "ui_videowidget.h"

VideoWidget::VideoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoWidget)
{
    ui->setupUi(this);

}

VideoWidget::~VideoWidget()
{
    delete ui;
}

void VideoWidget::revurl(QString f){
    fileName = f;
    ui->lineEdit->setText(fileName);


        //初始化python模块
            Py_Initialize();
            if ( !Py_IsInitialized() )
            {
                return ;
            }

            PyRun_SimpleString("import sys");
            PyRun_SimpleString("sys.path.append('C:/Users/daisy/Desktop/facedet/')");

            //导入.py模块
            PyObject* pModule = PyImport_ImportModule("Face");
            if (!pModule)
            {
                qDebug()<<"Cant open python file!\n";
                return ;
            }


            //获取模块中的 函数
            PyObject* pFunhello= PyObject_GetAttrString(pModule,"detect_face");
            if(!pFunhello)
            {
                qDebug()<<"Get function hello failed";
                return ;
            }

            qDebug()<<fileName;
std::string str = fileName.toStdString();
const char* str1 = str.c_str();
qDebug()<<str1;
            PyObject *pArg = Py_BuildValue("(s)",str1);

            //调用直接获得的函数，并传递参数
            PyEval_CallObject(pFunhello, pArg);

//            //调用 函数
//            PyObject_CallFunction(pFunhello,NULL);
            //结束，释放python
            Py_Finalize();

//0719用这个播处理了的avi会出现
//DirectShowPlayerService::doRender: Unresolved error code 0x80040218 ()，
//下载了LAVFilters也没有，看说可以使用VLC来播放视频，可以试一下
        QString file = "C:/Users/daisy/Desktop/facedet/output.avi";
            playList = new QMediaPlaylist;

            playList->addMedia(QUrl(file));

            player = new QMediaPlayer;
            player->setPlaylist(playList);

            videoWidget = new QVideoWidget(ui->verticalWidget);
            videoWidget->setMinimumSize(560,400);
            player->setVideoOutput(videoWidget);
            videoWidget->show();
            player->play();



}

void VideoWidget::on_pushButton_clicked()
{
    emit sendurl(fileName);
    this->close();
}
