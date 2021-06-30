#include "MeshApp.h"
#include "data.h"
#include<qfiledialog.h>
#include<string>
#include<qobject.h>


using namespace std;

MeshApp::MeshApp(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	ui.calculate_pb->setVisible(false);

}

//��Ӧ�¼�
void MeshApp::on_calculateButton_clicked() {
	ui.calculate_pb->setVisible(true);
	ui.calculate_pb->setValue(0);
    ui.status->setText("pls wait~");
	// ��������
	int niter = ui.iter_input->text().toInt();
	this->_flow_->calculate(niter);
	ui.status->setText("complete!!");
	ui.calculate_pb->setVisible(false);
}

void MeshApp::on_actionOpen_triggered() {
	//�����ļ��Ի�����
	ui.calculate_pb->setVisible(true);
	QFileDialog* fileDialog = new QFileDialog(this);
	//�����ļ��Ի������
	fileDialog->setWindowTitle(tr("���ļ�"));
	//����Ĭ���ļ�·��
	fileDialog->setDirectory(".");
	//�����ļ�������
	QString filename = fileDialog->getOpenFileName(this);
	ui.status->setText(filename);
	ui.calculate_pb->setValue(20);
	this->_mesh = new Mesh();
	string mesh_path_str = filename.toStdString();
	const char* _Mesh_Path_ = mesh_path_str.c_str();
	_mesh->readGrid(_Mesh_Path_);
	ui.calculate_pb->setValue(50);

	this->_flow_ = new FlowField(*this->_mesh);
	ui.calculate_pb->setValue(100);
	ui.calculate_pb->setVisible(false);

	QObject::connect(this->_flow_, SIGNAL(__CalculateProgress_set(int)), this, SLOT(_calculateProgressBar_set(int)));
	QObject::connect(this->_flow_, SIGNAL(__TimerLabel_set(struct Timer*)), this, SLOT(_TimerLabel_set(struct Timer*)));
	QObject::connect(this->_flow_, SIGNAL(__iter_set(int)), this, SLOT(_Iter_set(int)));
	QObject::connect(this->_flow_, SIGNAL(__rms_set(int)), this, SLOT(_Rms_set(int)));

}

void MeshApp::on_actionSave_as_triggered() {
	ui.status->setText("save");
}

void MeshApp::_calculateProgressBar_set(int value) {
	ui.calculate_pb->setValue(value);
}

void MeshApp::_TimerLabel_set(struct Timer* timer) {
	ui.area_label->setText(QString::number(timer->area));
	ui.flux_res_label->setText(QString::number(timer->flux_res));
	ui.perem_label->setText(QString::number(timer->perem));
	ui.save_label->setText(QString::number(timer->save));
	ui.update_label->setText(QString::number(timer->update));
}

void MeshApp::_Iter_set(int iter) {
	ui.iter_label->setText(QString::number(iter));
}
void MeshApp::_Rms_set(int rms) {
	ui.rms_label->setText(QString::number(rms));
}