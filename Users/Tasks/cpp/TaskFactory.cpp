//#include "../h/TaskFactory.h"
//#include "../h/Open_task.h"
//#include "../h/Close_task.h"
//#include "../h/Change_task.h"
//#include <fstream>
//
//void serialise(std::ostream& ofs, const Task* task) {
//	if (Open_task* fir = dynamic_cast<Open_task*>(const_cast<Task*>(task))) {
//		ofs << 1 << " ";
//		operator<<(ofs, static_cast<Open_task*>(const_cast<Task*>(task)));
//	}
//	else if (Close_task* sec = dynamic_cast<Close_task*>(const_cast<Task*>(task))) {
//		ofs << 2 << " ";
//		operator<<(ofs, static_cast<Close_task*>(const_cast<Task*>(task)));
//	}
//	else if (Change_task* tpe = dynamic_cast<Change_task*>(const_cast<Task*>(task))) {
//		ofs << 3 << " ";
//		operator<<(ofs, static_cast<Change_task*>(const_cast<Task*>(task)));
//	}
//}
//
//void deserialization(std::istream& ifs, Task* task)
//{
//	int number;
//	ifs >> number;
//	ifs.ignore();
//	if (number == 1) {
//		task = new Open_task();
//		ifs >> task;
//	}
//	else if (number == 2) {
//		task = new Close_task();
//		ifs >> task;
//	}
//	else if (number == 3) {
//		task = new Change_task();
//		ifs >> task;
//	}
//}
