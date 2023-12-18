/*!
 * @file par_double_read_only.h
 * @brief ������������ �������� ��������� (������ ��� ������)
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
#include <cfloat>
#include "par_t.h"
#define DEBUG
 //! ������������ �������� ��������� (������ ��� ������)
class par_double_read_only_t : public par_t {
public:
    /*!
     * ������������ �������� ��������� (������ ��� ������, ����������)
     */
    virtual ~par_double_read_only_t() = default;

    /*!
     * ���������� ��������
     * @return ��������
     */
    virtual double get_value() const = 0;

    /*!
     * ������������� ��������
     * @param value ��������
     */
    virtual void set_value(const double value) = 0;

    /*!
     * ���������� �������� �� ���������
     * @return �������� �� ���������
     */
    virtual double get_default_value() const = 0;

    /*!
     * ���������� ����������� ��������
     * @return ����������� ��������
     */
    virtual double get_min_value() const = 0;

    /*!
     * ���������� ������������ ��������
     * @return ������������ ��������
     */
    virtual double get_max_value() const = 0;

    /*!
     * ���������� ������� ���������
     * @return ������� ���������
     */
    virtual const char* get_measure() const = 0;

#ifdef DEBUG
protected:
    double* debug_value;        //!< �������� (��� �������)
    bool* debug_valid;          //!< ������������� (��� �������)
    par_status_t* debug_status; //!< ��������� (��� �������)
#endif
};

/*!
 * ������� ������������ �������� ��������� (������ ��� ������)
 * @param list_id ������������� ������ ���������� (0 - �������� �� ����������� ������)
 * @param text_id ��������� ������������� ���������
 * @param name ��������
 * @param default_value �������� �� ���������
 * @param min_value ����������� ��������
 * @param max_value ������������ ��������
 * @param measure ������� ��������� ���������
 */
extern "C" LIBIMIT_API par_double_read_only_t * __stdcall create_par_double_read_only(const unsigned char list_id, const char* text_id, const char* name, const double default_value = 0., const double min_value = -DBL_MAX, const double max_value = DBL_MAX, const char* measure = nullptr);

/*!
 * ���������� ������������ �������� ��������� (������ ��� ������)
 * @par par ������������ ��������
 */
extern "C" LIBIMIT_API void __stdcall destroy_par_double_read_only(par_double_read_only_t * par);

#endif
