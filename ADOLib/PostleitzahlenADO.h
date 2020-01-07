#pragma once

#include "ADOLib.h"

namespace ADOLib
{

	public ref class PostleitzahlenADO
	{
	private:
		PostleitzahlenADO();


	public:

		static int GetNextKey()
		{

			int retValue = 0;

			String^ SQL = "SELECT MAX(PRIMARYKEY) FROM POSTLEITZAHLEN";
			Object^ obj = DBConnection::ExecuteScalar(SQL);

			if (obj != System::DBNull::Value)
				retValue = Convert::ToInt32(obj);

			return ++retValue;
		}


		static bool InsertPLZ(int key, String^ PLZ, String^ Ort)
		{

			if (IstPostleitzahlVorhanden(PLZ, Ort))
				return false;

			String^ SQL = "INSERT INTO POSTLEITZAHLEN ";
			SQL += "(PRIMARYKEY, PLZ, ORT) ";
			SQL += "VALUES (";
			SQL += key.ToString() + ", ";
			SQL += DBConnection::Quote(PLZ) + ", ";
			SQL += DBConnection::Quote(Ort) + ")";

			return DBConnection::ExecuteNonQuery(SQL) > 0;

		}


		static int DeleteTable()
		{
			String^ SQL = "TRUNCATE TABLE POSTLEITZAHLEN";
			return DBConnection::ExecuteNonQuery(SQL);
		}

		static bool DeleteEntry(int key)
		{
			String^ SQL = "DELETE FROM POSTLEITZAHLEN ";
			SQL += " WHERE PRIMARYKEY = " + key.ToString();

			return DBConnection::ExecuteNonQuery(SQL) > 0;

		}

		static bool IstPostleitzahlVorhanden(String^ PLZ, String^ Ort)
		{

			bool retValue = false;

			String^ SQL = "SELECT COUNT(*) FROM POSTLEITZAHLEN ";
			SQL += "WHERE PLZ = " + DBConnection::Quote(PLZ);
			SQL += " AND ORT = " + DBConnection::Quote(Ort);

			Object^ obj = DBConnection::ExecuteScalar(SQL);

			if (obj != DBNull::Value)
				retValue = Convert::ToInt64(obj) > 0;


			return retValue;

		}

		static DataView^ GetPostleitzahlenDataView()
		{

			String^ SQL = "SELECT PRIMARYKEY, PLZ, ORT FROM POSTLEITZAHLEN ORDER BY PLZ";

			// Die DataView wird für das Filtern oder das Hinzufügen von 
			// Datensätzen benötigt.

			DataView^ dataView = gcnew DataView(GetDataTable(SQL));

			return dataView;

		}


		static DataTable^ GetDataTable(String^ SQL)
		{
			DataTable^ dataTable = gcnew DataTable();

			if (DBConnection::DBConn != nullptr && DBConnection::DBConn->State != ConnectionState::Open)
				return dataTable;

			try
			{
				// Der OleDbDataAdapter bildet eine Verbindung zwischen dem DataSet
				// und einer Datenquelle, über die Daten abgerufen und gespeichert
				// werden.
				// Der OleDbAdapter stellt diese Verbindung bereit, indem er mit 
				// 'Fill' Daten aus der Datenquelle in das DataSet lädt und im 
				// DataSet vorgenommene Änderungen mit 'Update' zurück an die 
				// Datenquelle sendet.
				OleDbDataAdapter^ da = gcnew OleDbDataAdapter(SQL, DBConnection::DBConn);
				da->Fill(dataTable);

			}
			catch (Exception ^ ex)
			{
				MessageBox::Show(ex->Message, "GetDataTable", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}

			return dataTable;

		}


		static OleDbDataReader^ GetPostleitzahl(int key)
		{

			OleDbDataReader^ dataReader = nullptr;

			String^ SQL = "SELECT PRIMARYKEY, PLZ, ORT, TIMESTAMP ";
			SQL += "FROM POSTLEITZAHLEN ";
			SQL += "WHERE PRIMARYKEY = " + key.ToString();

			try
			{
				OleDbCommand^ cmd = gcnew OleDbCommand(SQL, DBConnection::DBConn);
				dataReader = cmd->ExecuteReader();

			}
			catch (Exception ^ ex)
			{
				MessageBox::Show(ex->Message, "GetPostleitzahl", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}

			return dataReader;


		}


		static bool UpdatePLZ(int key, String^ PLZ, String^ Ort)
		{

			String^ SQL = "UPDATE POSTLEITZAHLEN ";
			SQL += "SET PLZ = " + DBConnection::Quote(PLZ) + ", ";
			SQL += "ORT = " + DBConnection::Quote(Ort);
			SQL += " WHERE PRIMARYKEY = " + key.ToString();

			return DBConnection::ExecuteNonQuery(SQL) > 0;

		}


	};

}