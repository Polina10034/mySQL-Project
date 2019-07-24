#include <mysqlx/xapi.h>
#include <iostream>

using namespace std;

int main() {
	char err_msg[256] = {};
	mysqlx_error_t *err_code = 0;
	


	//creration of an sql connection aka session to the mysql server
	mysqlx_session_t* sess = mysqlx_get_session("localhost", DEFAULT_MYSQLX_PORT, "root", "your PASSWORD", "sakila", &err_code);
	if (NULL == sess) {
		cerr << err_msg << endl;
		exit(0);
	}

	char query1[] = { "show tables" };

	mysqlx_result_t* res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);

	if (NULL != res) {
		char buff[256]; size_t size = 0;

		do {
			mysqlx_row_t* row = mysqlx_row_fetch_one(res);
			while (NULL != row) {
				size = sizeof(buff);
				mysqlx_get_bytes(row, 0, 0, buff, &size);
				cout << buff << endl;
				row = mysqlx_row_fetch_one(res);
			}
		} while (RESULT_OK == mysqlx_next_result(res));
	}
	else {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}

	cout << "------------------------" << endl;

	char query2[] = {
		"SELECT actor_id, first_name, last_name, concat(last_update,'') as last_update "\
		"FROM `actor`;"
	};

	res = mysqlx_sql(sess, query2, MYSQLX_NULL_TERMINATED);

	if (NULL != res) {
		char buff[256]; size_t size = 0;
		uint32_t cols = mysqlx_column_get_count(res);

		do {
			mysqlx_row_t* row = mysqlx_row_fetch_one(res);
			while (NULL != row) {
				for (uint32_t i = 0; i < cols; ++i) {
					size = sizeof(buff);
					mysqlx_get_bytes(row, i, 0, buff, &size);
					int id;
					switch (i) {
					case 0:
						id = 0;
						memcpy(&id, buff, size);
						cout << id;
						break;
					case 1:
						cout << buff;
						break;
					case 2:
						cout << buff;
						break;
					case 3:
						cout << buff;
						break;
					default:
						cout << "undefined";
					}
					if (9 > size)
						cout << "\t";
					cout << "\t|\t";
				}
				cout << endl;
				row = mysqlx_row_fetch_one(res);
			}
		} while (RESULT_OK == mysqlx_next_result(res));
	}
	else {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}

	mysqlx_session_close(sess);

	getchar();
	return 0;
}