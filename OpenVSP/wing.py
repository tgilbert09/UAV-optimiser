"""Test the OpenVSP Python Interface."""
from __future__ import print_function

import openvsp as vsp

stdout = vsp.cvar.cstdout
errorMgr = vsp.ErrorMgrSingleton_getInstance()

# ==== Test Enums ==== #
print("SET_ALL = ", vsp.SET_ALL)
print("SET_SHOWN = ", vsp.SET_SHOWN)
print("SET_NOT_SHOWN = ", vsp.SET_NOT_SHOWN)
print("SET_FIRST_USER = ", vsp.SET_FIRST_USER)
print("EXPORT_FELISA = ", vsp.EXPORT_FELISA)
print("EXPORT_XSEC = ", vsp.EXPORT_XSEC)
print("EXPORT_STL = ", vsp.EXPORT_STL)
print("EXPORT_AWAVE = ", vsp.EXPORT_AWAVE)
print("EXPORT_NASCART = ", vsp.EXPORT_NASCART)
print("EXPORT_POVRAY = ", vsp.EXPORT_POVRAY)
print("EXPORT_CART3D = ", vsp.EXPORT_CART3D)
print("EXPORT_VORXSEC = ", vsp.EXPORT_VORXSEC)
print("EXPORT_XSECGEOM = ", vsp.EXPORT_XSECGEOM)
print("EXPORT_GMSH = ", vsp.EXPORT_GMSH)
print("EXPORT_X3D = ", vsp.EXPORT_X3D)
print("EXPORT_STEP = ", vsp.EXPORT_STEP)
print("VSP_OK = ", vsp.VSP_OK)
print("VSP_INVALID_PTR = ", vsp.VSP_INVALID_PTR)
print("VSP_CANT_FIND_TYPE = ", vsp.VSP_CANT_FIND_TYPE)
print("VSP_CANT_FIND_PARM = ", vsp.VSP_CANT_FIND_PARM)
print("VSP_CANT_FIND_NAME = ", vsp.VSP_CANT_FIND_NAME)
print("VSP_INVALID_GEOM_ID = ", vsp.VSP_INVALID_GEOM_ID)
print("VSP_FILE_DOES_NOT_EXIST = ", vsp.VSP_FILE_DOES_NOT_EXIST)
print("VSP_FILE_WRITE_FAILURE = ", vsp.VSP_FILE_WRITE_FAILURE)
print("VSP_WRONG_XSEC_TYPE = ", vsp.VSP_WRONG_XSEC_TYPE)
print("VSP_WRONG_FILE_TYPE = ", vsp.VSP_WRONG_FILE_TYPE)
print("VSP_INDEX_OUT_RANGE = ", vsp.VSP_INDEX_OUT_RANGE)
print("VSP_INVALID_XSEC_ID = ", vsp.VSP_INVALID_XSEC_ID)
print("VSP_INVALID_ID = ", vsp.VSP_INVALID_ID)
print("VSP_CANT_SET_NOT_EQ_PARM = ", vsp.VSP_CANT_SET_NOT_EQ_PARM)
print("SYM_XY = ", vsp.SYM_XY)
print("SYM_XZ = ", vsp.SYM_XZ)
print("SYM_YZ = ", vsp.SYM_YZ)
print("SYM_ROT_X = ", vsp.SYM_ROT_X)
print("SYM_ROT_Y = ", vsp.SYM_ROT_Y)
print("SYM_ROT_Z = ", vsp.SYM_ROT_Z)
print("SYM_PLANAR_TYPES = ", vsp.SYM_PLANAR_TYPES)
print("SYM_NUM_TYPES = ", vsp.SYM_NUM_TYPES)
print("XSEC_FUSE = ", vsp.XSEC_FUSE)
print("XSEC_STACK = ", vsp.XSEC_STACK)
print("XSEC_WING = ", vsp.XSEC_WING)
print("XSEC_CUSTOM = ", vsp.XSEC_CUSTOM)
print("XSEC_NUM_TYPES = ", vsp.XSEC_NUM_TYPES)
print("X_DIR = ", vsp.X_DIR)
print("Y_DIR = ", vsp.Y_DIR)
print("Z_DIR = ", vsp.Z_DIR)
print("XS_SHIFT_LE = ", vsp.XS_SHIFT_LE)
print("XS_SHIFT_MID = ", vsp.XS_SHIFT_MID)
print("XS_SHIFT_TE = ", vsp.XS_SHIFT_TE)
print("XS_POINT = ", vsp.XS_POINT)
print("XS_CIRCLE = ", vsp.XS_CIRCLE)
print("XS_ELLIPSE = ", vsp.XS_ELLIPSE)
print("XS_SUPER_ELLIPSE = ", vsp.XS_SUPER_ELLIPSE)
print("XS_ROUNDED_RECTANGLE = ", vsp.XS_ROUNDED_RECTANGLE)
print("XS_GENERAL_FUSE = ", vsp.XS_GENERAL_FUSE)
print("XS_FILE_FUSE = ", vsp.XS_FILE_FUSE)
print("XS_FOUR_SERIES = ", vsp.XS_FOUR_SERIES)
print("XS_SIX_SERIES = ", vsp.XS_SIX_SERIES)
print("XS_BICONVEX = ", vsp.XS_BICONVEX)
print("XS_WEDGE = ", vsp.XS_WEDGE)
print("XS_BEZIER = ", vsp.XS_BEZIER)
print("XS_FILE_AIRFOIL = ", vsp.XS_FILE_AIRFOIL)
print("XS_NUM_TYPES = ", vsp.XS_NUM_TYPES)
print("XSEC_BOTH_SIDES = ", vsp.XSEC_BOTH_SIDES)
print("XSEC_LEFT_SIDE = ", vsp.XSEC_LEFT_SIDE)
print("XSEC_RIGHT_SIDE = ", vsp.XSEC_RIGHT_SIDE)
print("IMPORT_STL = ", vsp.IMPORT_STL)
print("IMPORT_NASCART = ", vsp.IMPORT_NASCART)
print("IMPORT_CART3D_TRI = ", vsp.IMPORT_CART3D_TRI)
print("IMPORT_XSEC_MESH = ", vsp.IMPORT_XSEC_MESH)
print("IMPORT_PTS = ", vsp.IMPORT_PTS)
print("NO_FILE_TYPE        = ", vsp.NO_FILE_TYPE)
print("COMP_GEOM_TXT_TYPE  = ", vsp.COMP_GEOM_TXT_TYPE)
print("COMP_GEOM_CSV_TYPE  = ", vsp.COMP_GEOM_CSV_TYPE)
print("DRAG_BUILD_TSV_TYPE = ", vsp.DRAG_BUILD_TSV_TYPE)
print("SLICE_TXT_TYPE      = ", vsp.SLICE_TXT_TYPE)
print("MASS_PROP_TXT_TYPE  = ", vsp.MASS_PROP_TXT_TYPE)
print("DEGEN_GEOM_CSV_TYPE = ", vsp.DEGEN_GEOM_CSV_TYPE)
print("DEGEN_GEOM_M_TYPE   = ", vsp.DEGEN_GEOM_M_TYPE)
print("CFD_STL_TYPE = ", vsp.CFD_STL_TYPE)
print("CFD_POLY_TYPE = ", vsp.CFD_POLY_TYPE)
print("CFD_TRI_TYPE = ", vsp.CFD_TRI_TYPE)
print("CFD_OBJ_TYPE = ", vsp.CFD_OBJ_TYPE)
print("CFD_DAT_TYPE = ", vsp.CFD_DAT_TYPE)
print("CFD_KEY_TYPE = ", vsp.CFD_KEY_TYPE)
print("CFD_GMSH_TYPE = ", vsp.CFD_GMSH_TYPE)
print("CFD_SRF_TYPE = ", vsp.CFD_SRF_TYPE)
print("CFD_TKEY_TYPE = ", vsp.CFD_TKEY_TYPE)
print("INT_DATA = ", vsp.INT_DATA)
print("DOUBLE_DATA = ", vsp.DOUBLE_DATA)
print("STRING_DATA = ", vsp.STRING_DATA)
print("VEC3D_DATA = ", vsp.VEC3D_DATA)
print("MESH_INDEXED_TRI = ", vsp.MESH_INDEXED_TRI)
print("MESH_SLICE_TRI = ", vsp.MESH_SLICE_TRI)
print("GEOM_XSECS = ", vsp.GEOM_XSECS)
print("CFD_STL_FILE_NAME = ", vsp.CFD_STL_FILE_NAME)
print("CFD_POLY_FILE_NAME = ", vsp.CFD_POLY_FILE_NAME)
print("CFD_TRI_FILE_NAME = ", vsp.CFD_TRI_FILE_NAME)
print("CFD_OBJ_FILE_NAME = ", vsp.CFD_OBJ_FILE_NAME)
print("CFD_DAT_FILE_NAME = ", vsp.CFD_DAT_FILE_NAME)
print("CFD_KEY_FILE_NAME = ", vsp.CFD_KEY_FILE_NAME)
print("CFD_GMSH_FILE_NAME = ", vsp.CFD_GMSH_FILE_NAME)
print("CFD_SRF_FILE_NAME = ", vsp.CFD_SRF_FILE_NAME)
print("CFD_TKEY_FILE_NAME = ", vsp.CFD_TKEY_FILE_NAME)
print("CFD_NUM_FILE_NAMES = ", vsp.CFD_NUM_FILE_NAMES)
print("CFD_MIN_EDGE_LEN = ", vsp.CFD_MIN_EDGE_LEN)
print("CFD_MAX_EDGE_LEN = ", vsp.CFD_MAX_EDGE_LEN)
print("CFD_MAX_GAP = ", vsp.CFD_MAX_GAP)
print("CFD_NUM_CIRCLE_SEGS = ", vsp.CFD_NUM_CIRCLE_SEGS)
print("CFD_GROWTH_RATIO = ", vsp.CFD_GROWTH_RATIO)
print("CFD_LIMIT_GROWTH_FLAG = ", vsp.CFD_LIMIT_GROWTH_FLAG)
print("CFD_INTERSECT_SUBSURFACE_FLAG = ", vsp.CFD_INTERSECT_SUBSURFACE_FLAG)
print("CFD_HALF_MESH_FLAG = ", vsp.CFD_HALF_MESH_FLAG)
print("CFD_FAR_FIELD_FLAG = ", vsp.CFD_FAR_FIELD_FLAG)
print("CFD_FAR_MAX_EDGE_LEN = ", vsp.CFD_FAR_MAX_EDGE_LEN)
print("CFD_FAR_MAX_GAP = ", vsp.CFD_FAR_MAX_GAP)
print("CFD_FAR_NUM_CIRCLE_SEGS = ", vsp.CFD_FAR_NUM_CIRCLE_SEGS)
print("CFD_FAR_SIZE_ABS_FLAG = ", vsp.CFD_FAR_SIZE_ABS_FLAG)
print("CFD_FAR_LENGTH = ", vsp.CFD_FAR_LENGTH)
print("CFD_FAR_WIDTH = ", vsp.CFD_FAR_WIDTH)
print("CFD_FAR_HEIGHT = ", vsp.CFD_FAR_HEIGHT)
print("CFD_FAR_X_SCALE = ", vsp.CFD_FAR_X_SCALE)
print("CFD_FAR_Y_SCALE = ", vsp.CFD_FAR_Y_SCALE)
print("CFD_FAR_Z_SCALE = ", vsp.CFD_FAR_Z_SCALE)
print("CFD_FAR_LOC_MAN_FLAG = ", vsp.CFD_FAR_LOC_MAN_FLAG)
print("CFD_FAR_LOC_X = ", vsp.CFD_FAR_LOC_X)
print("CFD_FAR_LOC_Y = ", vsp.CFD_FAR_LOC_Y)
print("CFD_FAR_LOC_Z = ", vsp.CFD_FAR_LOC_Z)
print("CFD_WAKE_SCALE = ", vsp.CFD_WAKE_SCALE)
print("CFD_WAKE_ANGLE = ", vsp.CFD_WAKE_ANGLE)
print("POINT_SOURCE = ", vsp.POINT_SOURCE)
print("LINE_SOURCE = ", vsp.LINE_SOURCE)
print("BOX_SOURCE = ", vsp.BOX_SOURCE)
print("NUM_SOURCE_TYPES = ", vsp.NUM_SOURCE_TYPES)
print("XDDM_VAR = ", vsp.XDDM_VAR)
print("XDDM_CONST = ", vsp.XDDM_CONST)
print("NORMAL_SURF = ", vsp.NORMAL_SURF)
print("WING_SURF = ", vsp.WING_SURF)
print("NUM_SURF_TYPES = ", vsp.NUM_SURF_TYPES)
print("SS_LINE = ", vsp.SS_LINE)
print("SS_RECTANGLE = ", vsp.SS_RECTANGLE)
print("SS_ELLIPSE = ", vsp.SS_ELLIPSE)
print("SS_NUM_TYPES = ", vsp.SS_NUM_TYPES)
print("AR_WSECT_DRIVER = ", vsp.AR_WSECT_DRIVER)
print("SPAN_WSECT_DRIVER = ", vsp.SPAN_WSECT_DRIVER)
print("AREA_WSECT_DRIVER = ", vsp.AREA_WSECT_DRIVER)
print("TAPER_WSECT_DRIVER = ", vsp.TAPER_WSECT_DRIVER)
print("AVEC_WSECT_DRIVER = ", vsp.AVEC_WSECT_DRIVER)
print("ROOTC_WSECT_DRIVER = ", vsp.ROOTC_WSECT_DRIVER)
print("TIPC_WSECT_DRIVER = ", vsp.TIPC_WSECT_DRIVER)
print("SECSWEEP_WSECT_DRIVER = ", vsp.SECSWEEP_WSECT_DRIVER)
print("NUM_WSECT_DRIVER = ", vsp.NUM_WSECT_DRIVER)
print("SWEEP_WSECT_DRIVER = ", vsp.SWEEP_WSECT_DRIVER)
print("SWEEPLOC_WSECT_DRIVER = ", vsp.SWEEPLOC_WSECT_DRIVER)
print("SECSWEEPLOC_WSECT_DRIVER = ", vsp.SECSWEEPLOC_WSECT_DRIVER)

vsp.VSPRenew()
errorMgr.PopErrorAndPrint(stdout)



geoms = vsp.FindGeoms()

print("All geoms in Vehicle.")
print(geoms)

vsp.SetComputationFileName(vsp.DEGEN_GEOM_CSV_TYPE, 'wing_DegenGeom.csv')

# Wing Properties
wing_id = vsp.AddGeom("WING")
vsp.SetParmVal(wing_id, "TotalSpan", "WingGeom", 10)
vsp.SetParmVal(wing_id, "Sweep", "XSec_1", 0)
vsp.SetParmVal(wing_id, "Tip_Chord", "XSec_1", 0.3)
vsp.SetParmVal(wing_id, "Root_Chord", "XSec_1", 0.3)
vsp.SetParmVal(wing_id, "ThickChord", "XSecCurve_0", 0.18)
vsp.SetParmVal(wing_id, "Camber", "XSecCurve_0", 0.04)
vsp.SetParmVal(wing_id, "CamberLoc", "XSecCurve_0", 0.4)
vsp.SetParmVal(wing_id, "ThickChord", "XSecCurve_1", 0.18)
vsp.SetParmVal(wing_id, "Camber", "XSecCurve_1", 0.04)
vsp.SetParmVal(wing_id, "CamberLoc", "XSecCurve_1", 0.4)
vsp.SetParmVal(wing_id, "SectTess_U", "XSec_1", 30)

# Make the geometry file
vsp.ComputeDegenGeom(vsp.SET_ALL, vsp.DEGEN_GEOM_CSV_TYPE)


geoms = vsp.FindGeoms()

print("End of second use case, all geoms in Vehicle.")
print(geoms)

vsp.WriteVSPFile("wing.vsp3")





'''
analysis_name = "VSPAEROSinglePoint";
print( "{0} \n".format(analysis_name))

#Set defaults
vsp.SetAnalysisInputDefaults( analysis_name )


#Close and open the file
vsp.ClearVSPModel()
vsp.Update()
vsp.ReadVSPFile( "wing.vsp3" ) # Sets VSP3 file name
vsp.Update()


#Analysis: VSPAero Compute Geometry to Create Vortex Lattice DegenGeom File ====//
compgeom_name = "VSPAEROComputeGeometry"
print( compgeom_name )

#Set defaults
vsp.SetAnalysisInputDefaults( compgeom_name )

#list inputs, type, and current values
vsp.PrintAnalysisInputs( compgeom_name )

#Execute
print( "Executing..." );
compgeom_resid = vsp.ExecAnalysis( compgeom_name );
print( "COMPLETE" );

#Get & Display Results
vsp.PrintResults( compgeom_resid )

# === Analysis: VSPAero Single Point ====//
#Set defaults
vsp.SetAnalysisInputDefaults( analysis_name )

# Reference geometry set
geom_set = [0, 0]
ref_flag = [0, 0]

wid = vsp.FindGeomsWithName( "WingGeom" )
vsp.SetIntAnalysisInput( analysis_name, "GeomSet", geom_set, 0 )
vsp.SetIntAnalysisInput( analysis_name, "RefFlag", ref_flag, 0 )
vsp.SetStringAnalysisInput( analysis_name, "WingID", wid, 0 )

# Freestream Parameters
alpha = [0.0, 10.0]
mach = [0.1]
vsp.SetDoubleAnalysisInput( analysis_name, "Alpha", alpha, 0 )
vsp.SetDoubleAnalysisInput( analysis_name, "Mach", mach, 0 )

vsp.Update()

#list inputs, type, and current values
vsp.PrintAnalysisInputs( analysis_name )
print( "" )

print("Do we have an error?? {0}".format(errorMgr.GetErrorLastCallFlag() ))

vsp.Update()

#Execute
print( "Executing..." )
#rid = vsp.parse_results_object(vsp.ExecAnalysis( analysis_name ))
rid = vsp.ExecAnalysis( analysis_name )
print( "COMPLETE" )

print(rid)

#Get & Display Results
vsp.printResults( rid );

results_names = vsp.GetAllDataNames( rid );
res_id = vsp.GetStringResults( rid, results_names[0] , 0 )

CL = vsp.GetDoubleResults( res_id[0], "CL", 0 )
cl = vsp.GetDoubleResults( res_id[1], "cl", 0 )

Print( "CL at 0 angle of attack: ", false );

for i in range(len(CL)):
    print(CL[i])

for i in range(len(cl)):
    print(cl[i])

'''

    

# Check for errors

num_err = errorMgr.GetNumTotalErrors()
for i in range(0, num_err):
    err = errorMgr.PopLastError()
    print("error = ", err.m_ErrorString)
