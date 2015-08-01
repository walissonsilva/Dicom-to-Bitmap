
#ifndef MEDICALIMAGE_H
#define MEDICALIMAGE_H
#include "dcmtk/dcmdata/dcfilefo.h"
#include "dcmtk/dcmdata/dcdeftag.h"
#include "dcmtk/config/osconfig.h"
#include "dcmtk/dcmdata/dctk.h"
#include "dcmtk/dcmdata/dcuid.h" /* for dcmtk version name */
#include "dcmtk/dcmdata/dcddirif.h" /* for class DicomDirInterface */
#include "dcmtk/ofstd/ofstd.h" /* for class OFStandard */
#include "dcmtk/ofstd/ofconapp.h" /* for class OFConsoleApplication */
#include "dcmtk/ofstd/ofcond.h" /* for class OFCondition */
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class MedicalImage
{
    public:
        MedicalImage(void);
        MedicalImage(char* filename);
        ~MedicalImage(void);

        void printInFile(char* filename);

        bool OpenDicomFile(const char* filename);

        int* loadImage(void);
        int* getImage(void);

        const char* TransferSyntaxUID(void);
        const char* UID(void);
        const char* ImplementationClassUID(void);
        const char* MediaStorageInstanceUID(void);
        const char* MediaStorageSOPUID(void);
        const char* ImplementationVersionName(void);
        const char* SourceApplicationEntityTitle(void);
        const char* PrivateInformationCreatorUID(void);
        const char* PrivateInformation(void);
        const char* ImageType(void);
        const char* InstitutionName(void);
        const char* Manufacturer(void);
        const char* ManufacturerModelName(void);
        const char* Modality(void);
        const char* SOPClassUID(void);
        const char* ImagePositionPatient(void);
        const char* ImageOrientationPatient(void);
        const char* PatientsName(void);
        const char* PatientsSex(void);
        const char* PixelSpacing(void);
        const char*	SOPInstanceUID(void);
        const char*	StudyDate(void);
        const char* AcquisitionDate(void);
        const char* ContentDate(void);
        const char* StudyTime(void);
        const char* AcquisitionTime(void);
        const char* ContentTime(void);
        const char*	PatientID(void);
        const char*	PatientsBirthDate(void);
        const char*	PatientsAge(void);
        const char* ContrastBolusAgent(void);
        const char* ScanOptions(void);
        const char* DeviceSerialNumber(void);
        const char* SoftwareVersion(void);
        const char* RotationDirection(void);
        const char* ConvolutionKernel(void);
        const char* PatientPosition(void);
        const char* PhotometricInterpretation(void);

        Float64 SliceThickness(void);
        Float64 SliceLocation(void);

        long int PixelDataGroupLength(void);
        long int Rows(void);
        long int Columns(void);

        float getVoxelVolume(void);

    private:

        DcmFileFormat dcm; 					// The DICOM file format object.
        OFCondition cond;						// Condition object. Check return values of all dcmtk functions when possible.
        int* image;
};
#endif
