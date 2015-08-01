#include "MedicalImage.h"

MedicalImage::MedicalImage(void)
{
    image = NULL;
}

MedicalImage::~MedicalImage(void)
{
 if(image != NULL)
        delete [] image;
}

MedicalImage::MedicalImage(char* filename)
{
  if(!OpenDicomFile(filename))
        std::cerr << "Error reading DICOM file: [" << cond.text() << "] at [" << filename << "]." << endl;
}

bool MedicalImage::OpenDicomFile(const char* filename)
{
    DcmFileFormat fileformat;
    //cout << fileformat.loadFile(filename,  EXS_Unknown, EGL_noChange, 10000, ERM_autoDetect).bad() << endl;
    if (fileformat.loadFile(filename).good())
    {
        DcmDataset *dataset = fileformat.getDataset();

        // decompress data set if compressed
        dataset->chooseRepresentation(EXS_BigEndianExplicit, NULL);

        // check if everything went well
        if (dataset->canWriteXfer(EXS_BigEndianExplicit))
        {
            fileformat.saveFile("DICOMtemp.dcm", EXS_BigEndianExplicit);

            cond = dcm.loadFile("DICOMtemp.dcm");
          if (cond.bad())
              return false;

          return true;
        }
    }

    return false;
}


const char* MedicalImage::TransferSyntaxUID(void)
{
  const char* temp;
    cond = dcm.getDataset()->findAndGetString(DCM_TransferSyntaxUID, temp);
    if (cond.bad())
        return cond.text();

    return temp;
}
const char* MedicalImage::UID(void)
{
  const char* temp;
    cond = dcm.getDataset()->findAndGetString(DCM_UID, temp);
    if (cond.bad())
        return cond.text();

    return temp;
}
const char* MedicalImage::ImplementationClassUID(void)
{
  const char* temp;
    cond = dcm.getDataset()->findAndGetString(DCM_ImplementationClassUID, temp);
    if (cond.bad())
        return cond.text();

    return temp;
}
const char* MedicalImage::MediaStorageInstanceUID(void)
{
  const char* temp;
    cond = dcm.getDataset()->findAndGetString(DCM_MediaStorageSOPInstanceUID, temp);
    if (cond.bad())
        return cond.text();

    return temp;
}
const char* MedicalImage::MediaStorageSOPUID(void)
{
  const char* temp;
    cond = dcm.getDataset()->findAndGetString(DCM_MediaStorageSOPClassUID, temp);
    if (cond.bad())
        return cond.text();

    return temp;
}
const char* MedicalImage::ImplementationVersionName(void)
{
  const char* temp;
    cond = dcm.getDataset()->findAndGetString(DCM_ImplementationVersionName, temp);
    if (cond.bad())
        return cond.text();

    return temp;
}
const char* MedicalImage::SourceApplicationEntityTitle(void)
{
  const char* temp;
    cond = dcm.getDataset()->findAndGetString(DCM_SourceApplicationEntityTitle, temp);
    if (cond.bad())
        return cond.text();

    return temp;
}
const char* MedicalImage::PrivateInformationCreatorUID(void)
{
  const char* temp;
    cond = dcm.getDataset()->findAndGetString(DCM_PrivateInformationCreatorUID, temp);
    if (cond.bad())
        return cond.text();

    return temp;
}
const char* MedicalImage::PrivateInformation(void)
{
  const char* temp;
    cond = dcm.getDataset()->findAndGetString(DCM_PrivateInformation, temp);
    if (cond.bad())
        return cond.text();

    return temp;
}
const char* MedicalImage::ImageType(void)
{
  const char* temp;
    cond = dcm.getDataset()->findAndGetString(DCM_ImageType, temp);
    if (cond.bad())
        return cond.text();

    return temp;
}

//---------------------------------------------------------------------
const char* MedicalImage::InstitutionName(void)
{
    const char* temp;
    cond = dcm.getDataset()->findAndGetString(DCM_InstitutionName, temp);
    if (cond.bad())
        return cond.text();

    return temp;
}

//---------------------------------------------------------------------
const char* MedicalImage::Manufacturer(void)
{
  const char* temp;
    cond = dcm.getDataset()->findAndGetString(DCM_Manufacturer, temp);
    if (cond.bad())
        return cond.text();

    return temp;
}

//--------------------------------------------------------------------------
const char* MedicalImage::ManufacturerModelName(void)
{
  const char* temp;
    cond = dcm.getDataset()->findAndGetString(DCM_ManufacturerModelName, temp);
    if (cond.bad())
        return cond.text();

    return temp;
}

//--------------------------------------------------------------------------
const char* MedicalImage::Modality(void)
{
  const char* temp;
    cond = dcm.getDataset()->findAndGetString(DCM_Modality, temp);
    if (cond.bad())
        return cond.text();

    return temp;
}

//--------------------------------------------------------------
const char* MedicalImage::SOPClassUID(void)
{
  const char* temp;
    cond = dcm.getDataset()->findAndGetString(DCM_SOPClassUID, temp);
    if (cond.bad())
        return cond.text();

    return temp;
}
//---------------------------------------------------------------------
const char* MedicalImage::ImagePositionPatient(void)
{
  const char* temp;
    cond = dcm.getDataset()->findAndGetString(DCM_ImagePositionPatient, temp);
    if (cond.bad())
        return cond.text();

    return temp;
}

//---------------------------------------------------------------------
const char* MedicalImage::ImageOrientationPatient(void)
{
  const char* temp;
    cond = dcm.getDataset()->findAndGetString(DCM_ImageOrientationPatient, temp);
    if (cond.bad())
        return cond.text();

    return temp;
}

//---------------------------------------------------------------------
const char* MedicalImage::PatientsName(void)
{
  const char* temp;
    cond = dcm.getDataset()->findAndGetString(DCM_PatientName, temp);
    if (cond.bad())
        return cond.text();

    return temp;
}

///--------------------------------------------------------------
const char* MedicalImage::PatientsSex(void)
{
  const char* temp;
    cond = dcm.getDataset()->findAndGetString(DCM_PatientSex, temp);
    if (cond.bad())
        return cond.text();

    return temp;
}

///--------------------------------------------------------------
const char* MedicalImage::PixelSpacing(void)
{
  const char* temp;
    cond = dcm.getDataset()->findAndGetString(DCM_PixelSpacing, temp);
    if (cond.bad())
        return cond.text();

    return temp;
}
///--------------------------------------------------------------
const char*	MedicalImage::SOPInstanceUID(void)
{
  const char* temp;
    cond = dcm.getDataset()->findAndGetString(DCM_SOPInstanceUID, temp);
    if (cond.bad())
        return cond.text();

    return temp;
}
///--------------------------------------------------------------
const char*	MedicalImage::StudyDate(void)
{
  const char* temp;
    cond = dcm.getDataset()->findAndGetString(DCM_StudyDate, temp);
    if (cond.bad())
        return cond.text();

    return temp;
}
///--------------------------------------------------------------
const char* MedicalImage::AcquisitionDate(void)
{
  const char* temp;
    cond = dcm.getDataset()->findAndGetString(DCM_AcquisitionDate, temp);
    if (cond.bad())
        return cond.text();

    return temp;
}
///--------------------------------------------------------------
const char* MedicalImage::ContentDate(void)
{
  const char* temp;
    cond = dcm.getDataset()->findAndGetString(DCM_ContentDate, temp);
    if (cond.bad())
        return cond.text();

    return temp;
}
///--------------------------------------------------------------
const char* MedicalImage::StudyTime(void)
{
  const char* temp;
    cond = dcm.getDataset()->findAndGetString(DCM_StudyTime, temp);
    if (cond.bad())
        return cond.text();

    return temp;
}
///--------------------------------------------------------------
const char* MedicalImage::AcquisitionTime(void)
{
  const char* temp;
    cond = dcm.getDataset()->findAndGetString(DCM_AcquisitionTime, temp);
    if (cond.bad())
        return cond.text();

    return temp;
}
///--------------------------------------------------------------
const char* MedicalImage::ContentTime(void)
{
  const char* temp;
    cond = dcm.getDataset()->findAndGetString(DCM_ContentTime, temp);
    if (cond.bad())
        return cond.text();

    return temp;
}
///--------------------------------------------------------------
const char*	MedicalImage::PatientID(void)
{
  const char* temp;
    cond = dcm.getDataset()->findAndGetString(DCM_PatientID, temp);
    if (cond.bad())
        return cond.text();

    return temp;
}
///--------------------------------------------------------------
const char*	MedicalImage::PatientsBirthDate(void)
{
  const char* temp;
    cond = dcm.getDataset()->findAndGetString(DCM_PatientBirthDate, temp);
    if (cond.bad())
        return cond.text();

    return temp;
}
///--------------------------------------------------------------
const char*	MedicalImage::PatientsAge(void)
{
  const char* temp;
    cond = dcm.getDataset()->findAndGetString(DCM_PatientAge, temp);
    if (cond.bad())
        return cond.text();

    return temp;
}
///--------------------------------------------------------------
const char* MedicalImage::ContrastBolusAgent(void)
{
  const char* temp;
    cond = dcm.getDataset()->findAndGetString(DCM_ContrastBolusAgent, temp);
    if (cond.bad())
        return cond.text();

    return temp;
}
///--------------------------------------------------------------
const char* MedicalImage::ScanOptions(void)
{
  const char* temp;
    cond = dcm.getDataset()->findAndGetString(DCM_ScanOptions, temp);
    if (cond.bad())
        return cond.text();

    return temp;
}
///--------------------------------------------------------------
const char* MedicalImage::DeviceSerialNumber(void)
{
  const char* temp;
    cond = dcm.getDataset()->findAndGetString(DCM_DeviceSerialNumber, temp);
    if (cond.bad())
        return cond.text();

    return temp;
}
///--------------------------------------------------------------
const char* MedicalImage::SoftwareVersion(void)
{
  const char* temp;
    cond = dcm.getDataset()->findAndGetString(DCM_SoftwareVersions, temp);
    if (cond.bad())
        return cond.text();

    return temp;
}
///--------------------------------------------------------------
const char* MedicalImage::RotationDirection(void)
{
  const char* temp;
    cond = dcm.getDataset()->findAndGetString(DCM_RotationDirection, temp);
    if (cond.bad())
        return cond.text();

    return temp;
}
///--------------------------------------------------------------
const char* MedicalImage::ConvolutionKernel(void)
{
  const char* temp;
    cond = dcm.getDataset()->findAndGetString(DCM_ConvolutionKernel, temp);
    if (cond.bad())
        return cond.text();

    return temp;
}
///--------------------------------------------------------------
const char* MedicalImage::PatientPosition(void)
{
  const char* temp;
    cond = dcm.getDataset()->findAndGetString(DCM_PatientPosition, temp);
    if (cond.bad())
        return cond.text();

    return temp;
}
///--------------------------------------------------------------
const char* MedicalImage::PhotometricInterpretation(void)
{
  const char* temp;
    cond = dcm.getDataset()->findAndGetString(DCM_PhotometricInterpretation, temp);
    if (cond.bad())
        return cond.text();

    return temp;
}
///--------------------------------------------------------------
Float64 MedicalImage::SliceThickness(void)
{
    Float64 temp;
    cond = dcm.getDataset()->findAndGetFloat64(DCM_SliceThickness,temp);
    if (cond.bad())
      return -1;
    else
        return temp;
}

Float64 MedicalImage::SliceLocation(void)
{
    Float64 temp;
    cond = dcm.getDataset()->findAndGetFloat64(DCM_SliceLocation, temp);
    if (cond.bad())
      return -1;
    else
        return temp;
}
//--------------------------------------------------------------------------
long int MedicalImage::PixelDataGroupLength(void)
{
    long int temp;
    cond = dcm.getDataset()->findAndGetLongInt(DCM_PixelData, temp);
    if (cond.bad())
      return -1;
    else
        return temp;
}

///--------------------------------------------------------------
long int MedicalImage::Rows(void)
{
    long int temp;
    cond = dcm.getDataset()->findAndGetLongInt(DCM_Rows, temp);
    if (cond.bad())
      return -1;
    else
        return temp;
}
///--------------------------------------------------------------
long int MedicalImage::Columns(void)
{
  long int temp;
    cond = dcm.getDataset()->findAndGetLongInt(DCM_Columns, temp);
    if (cond.bad())
      return -1;
    else
        return temp;
}
///--------------------------------------------------------------
int* MedicalImage::loadImage(void)
{
    long int i = 0;
    const Uint16 *img;
    cond = dcm.getDataset()->findAndGetUint16Array(DCM_PixelData, img);

    if (cond.bad())
    {
        std::cerr << "Error reading tag PixelData: [" << i <<"]" << cond.text() << endl;
        return NULL;
    }
    else
    {
        bool inv = false;
        long int size = Rows() * Columns();

        if(image != NULL)
            delete [] image;
        image = new int[size];

        for(i = 0; i < size && !inv; i ++)
        {
            if(img[i]>32678)
            inv=true;
        }

        Float64 offset;
        dcm.getDataset()->findAndGetFloat64(DCM_RescaleIntercept, offset);
        if(inv)
        {
            for(i = 0; i < size; i++)
            {
                if(img[i] > 32678)
                    image[i] =(int)(img[i] - 65536 + offset);
                else
                image[i] = (int)(img[i] + offset);
            }
        }
        else
        {
            for(i = 0; i < size; i++)
                image[i] = (int)(img[i] + offset);
        }

        return image;
    }
}

int* MedicalImage::getImage(void)
{
    return image;
}

float MedicalImage::getVoxelVolume(void)
{
    const char *widhei = PixelSpacing();

    size_t found;
    string width = widhei;
    string height = widhei;

    found = width.find_last_of("\\");
    width = width.substr(found+1);
    height = height.substr(0, found);

    float pixelwidth = (float)atof(width.c_str());
    float pixelHeight = (float)atof(height.c_str());
    float thickness = fabs(SliceThickness());

    float result = pixelwidth*pixelHeight*thickness;

    return result;
}
