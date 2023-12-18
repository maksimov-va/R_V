/*!
 * @file par_list.h
 * @brief ������ ���������� ���������
 * @author ���� �������
 * @copyright �� ��� "�����������������", ���-1
 * @details
 * #### ����� ����
 *    ���
 * #### �����������
 *    ���
 */
#pragma once
#ifdef __cplusplus
#include "par_t.h"
#define  DEBUG

 //! ������ ���������� ���������
class par_list_t : public par_t {
public:
    /*!
     * ������ ���������� ��������� (����������)
     */
    virtual ~par_list_t() = default;

    /*!
     * ������������� ���������
     * @param status ���������
    */
    virtual void set_list_status(const par_list_status_t status) = 0;

    /*!
     * ���������� ���������
     * @return ���������
    */
    virtual par_list_status_t get_list_status() const = 0;

#ifdef DEBUG
protected:
    par_list_status_t* debug_list_status; //!< ��������� ������ (��� �������)
    bool* debug_valid;                    //!< ������������� (��� �������)
    par_status_t* debug_status;           //!< ��������� ��������� (��� �������)
#endif
};

/*!
 * ������ ���������� ��������� (������������ ������ � ������ ����������)
 * @param list_id ������������� ������ ���������� (���������)
 * @param name �������� ������ ����������
 */
extern "C" LIBIMIT_API par_list_t * __stdcall create_par_list(const unsigned char list_id, const char* name);

/*!
 * ���������� ������ ���������� ���������
 * @par par ������������ ������
 */
extern "C" LIBIMIT_API void __stdcall destroy_par_list(par_list_t * par);

#endif
