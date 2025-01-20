{
'variables':{
'module_name': "zoomvideosdk",
'module_mac': "./../sdk/mac",
"module_linux":"./../sdk/linux",
"module_win32":"./../sdk/win32",
'module_32pdbfile_name':"./../sdk/win32/zoomvideosdk.pdb",
'module_32libfile_name':"./../sdk/win32/zoomvideosdk.lib",

"module_win64":"./../sdk/win64",
'module_64pdbfile_name':"./../sdk/win64/zoomvideosdk.pdb",
'module_64libfile_name':"./../sdk/win64/zoomvideosdk.lib",

'render_module_name': "zoomvideosdk_libuv",
'render_module_32pdbfile_name':"./../sdk/win32/zoomvideosdk_libuv.pdb",
'render_module_32libfile_name':"./../sdk/win32/zoomvideosdk_libuv.lib",

'render_module_64pdbfile_name':"./../sdk/win64/zoomvideosdk_libuv.pdb",
'render_module_64libfile_name':"./../sdk/win64/zoomvideosdk_libuv.lib",

'napi_util_module_name': "zoomvideosdk_napi_util",
'openssl_fips': '',
},
      "targets":[
	  {
 		'target_name':"<(napi_util_module_name)",
		'conditions':[
		  [
		  'OS=="mac"',
		  {
		      'defines':['__MACOS__'],
		      "xcode_settings":{
                    "DEBUG_INFORMATION_FORMAT": "dwarf-with-dsym",
                    "BUILD_DIR":"<(module_mac)",
                    "OTHER_CPLUSPLUSFLAGS" : [ '-ObjC++', "-std=c++20", "-stdlib=libc++",  '-fvisibility=hidden','-frtti'],
                    "DEPLOYMENT_POSTPROCESSING": "YES",
        
	        }
		  },
		  ],
      [
		  'OS=="linux"',
		  {
		   'product_dir':"<(module_linux)",
		  }
		  ],
		  [
		  'OS=="win" and target_arch=="x64"',
		  {
		   'product_dir':"<(module_win64)",
		  }
		  ],
		  [
		  'OS=="win" and target_arch=="ia32"',
		  {
			'product_dir':"<(module_win32)",
		  }
		  ],
		],
		"sources":[ "./lib/node_add_on/zoom_video_sdk_napi_util.cpp" ]
		},
      {
      'target_name':"<(module_name)",
      
      'conditions':[
      [
		  'OS=="mac"',
		  {
		      # 'product_dir':"<(module_mac)",
		      "dependencies": [ "<(napi_util_module_name)" ],
			  'sources':[
			  "./lib/node_add_on/electron_zoomvideosdk.pb.cc",
			  "./lib/node_add_on/zoom_video_sdk_node_addon.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_session_info_ctrl.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_audio_helper.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_video_helper.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_share_helper.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_user_helper.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_chat_helper.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_livestream_helper.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_rawdata_helper_mgr_class.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_cmd_channel_helper.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_phone_helper.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_recording_helper.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_remote_camera_control_helper.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_remote_control_helper.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_audio_setting.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_live_transcription_helper.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_share_setting.cpp",
			  "./lib/node_add_on/zoom_video_sdk_v8_to_c.cpp",
			  
			  "./lib/node_add_on/zoom_video_sdk_node_video_raw_data.cpp",
			  #"./lib/node_add_on/zoom_instant_node_audio_raw_data.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_rawdata_server_mgr.cpp",
			   "./lib/node_add_on/raw_data_format.cpp",
			  "./lib/node_add_on/uv_ipc_common.cpp",
			  "./lib/node_add_on/raw_data_uv_ipc_server.cpp",
			  
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_sdk_wrap_core.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_session_info_wrap_core.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_audio_helper_wrap_core.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_audio_setting_wrap_core.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_video_helper_wrap_core.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_share_helper_wrap_core.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_video_raw_data_helper.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_user_helper_wrap_core.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_chat_helper_wrap_core.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_livestream_helper_wrap_core.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_remote_camera_control_helper_wrap_core.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_cmd_channel_helper_wrap_core.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_phone_helper_wrap_core.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_recording_helper_wrap_core.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_live_transcription_helper_wrap_core.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_share_setting_wrap_core.cpp",
			  "./lib/node_add_on/zoom_video_sdk_napi_util_exporter.cpp",
			  
			  
			  "./lib/node_add_on/mac/share_info_helper.mm",
			  ],
			 'defines':['__MACOS__'],
			  # 'mac_framework_dirs':[
			  # './../sdk/mac/ZoomSDK',
			  # ],
			  'mac_bundle_resources': [
     			"../sdk/mac/zoomsdk_napi_util.node",
    			],
			  'link_settings':{
			  'libraries':[
			       "../sdk/mac/ZoomVideoSDK/VideoSDK.dylib",
			       "../sdk/mac/ZoomVideoSDK/libprotobuf.dylib",
			   ],
			   'include_dirs':[
			   "./lib/node_add_on/protobuf_src",
			   "./lib/node_add_on",
			   "./lib/node_add_on/export_h",
				],
			   },
   		      "xcode_settings":{
                    "DEBUG_INFORMATION_FORMAT": "dwarf-with-dsym",
                    "BUILD_DIR":"<(module_mac)",
                    "OTHER_CPLUSPLUSFLAGS" : [ '-ObjC++', "-std=c++20", "-stdlib=libc++",  '-fvisibility=hidden','-frtti'],
                    "OTHER_LDFLAGS": [ "-stdlib=libc++"],
                    "DEPLOYMENT_POSTPROCESSING": "YES",
                    # "BUILT_PRODUCTS_DIR":"$(SRCROOT)/../../../../../../Bin/Mac",
	        }
			   
		  },
		  ],
      [
		  'OS=="linux"',
		  { 
			  'sources':[
			  "./lib/node_add_on/electron_zoomvideosdk.pb.cc",
			  "./lib/node_add_on/zoom_video_sdk_node_addon.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_session_info_ctrl.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_audio_helper.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_video_helper.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_share_helper.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_user_helper.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_chat_helper.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_livestream_helper.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_rawdata_helper_mgr_class.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_cmd_channel_helper.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_phone_helper.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_recording_helper.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_remote_camera_control_helper.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_audio_setting.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_live_transcription_helper.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_share_setting.cpp",
			  "./lib/node_add_on/zoom_video_sdk_v8_to_c.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_video_raw_data.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_rawdata_server_mgr.cpp",
			  "./lib/node_add_on/raw_data_format.cpp",
			  "./lib/node_add_on/uv_ipc_common.cpp",
			  "./lib/node_add_on/raw_data_uv_ipc_server.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_sdk_wrap_core.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_session_info_wrap_core.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_audio_helper_wrap_core.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_audio_setting_wrap_core.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_video_helper_wrap_core.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_share_helper_wrap_core.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_video_raw_data_helper.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_user_helper_wrap_core.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_chat_helper_wrap_core.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_livestream_helper_wrap_core.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_remote_camera_control_helper_wrap_core.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_cmd_channel_helper_wrap_core.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_phone_helper_wrap_core.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_recording_helper_wrap_core.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_live_transcription_helper_wrap_core.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_share_setting_wrap_core.cpp",
			  "./lib/node_add_on/zoom_video_sdk_napi_util_exporter.cpp",
			  ],
			  'link_settings':{
          'libraries':[
			       "../sdk/linux/libprotobuf.a",
			    ],
			   'include_dirs':[
			   "./lib/node_add_on/protobuf_src",
			   "./lib/node_add_on",
			   "./lib/node_add_on/export_h",
				],
			  },
				'cflags_cc!': ['-fno-rtti']
		  }
		  ],
		  [
		  'OS=="win" and target_arch=="ia32"',
		  {
		     'configurations': {
				'Release': {
				  'msvs_settings': {
					'VCLinkerTool': {
					  'GenerateDebugInformation': 'true',
					  'GenerateMapFile': 'true',
					  'ProgramDatabaseFile': "<(module_32pdbfile_name)",
					},
					'VCCLCompilerTool': {
                     'RuntimeLibrary': '2',
                    },
				  }, 
				},
		  }, # configurations
		   'link_settings':{
			  'libraries':[
			   "./../sdk/win32/libprotobuf-lite.lib",
			   "./../sdk/win32/zoomvideosdk_napi_util.lib",
			   ],
			   },
		  }
		  ],
		  [
		  'OS=="win" and target_arch=="x64"',
		  {
		     'configurations': {
				'Release': {
				  'msvs_settings': {
					'VCLinkerTool': {
					  'GenerateDebugInformation': 'true',
					  'GenerateMapFile': 'true',
					  'ProgramDatabaseFile': "<(module_64pdbfile_name)",
					},
					'VCCLCompilerTool': {
                     'RuntimeLibrary': '2',
                    },
				  }, 
				},
		  }, # configurations
		   'link_settings':{
			  'libraries':[
			   "./../sdk/win64/libprotobuf-lite.lib",
			   "./../sdk/win64/zoomvideosdk_napi_util.lib",

			   ],
			   },
		  }
		  ],
		  [
		  'OS=="win"',
		  {
		  "dependencies": [ "<(napi_util_module_name)" ],
		  "sources":[
			  "./lib/node_add_on/electron_zoomvideosdk.pb.cc",
			  "./lib/node_add_on/zoom_video_sdk_node_addon.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_session_info_ctrl.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_audio_helper.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_video_helper.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_share_helper.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_user_helper.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_chat_helper.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_livestream_helper.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_rawdata_helper_mgr_class.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_cmd_channel_helper.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_phone_helper.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_recording_helper.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_remote_camera_control_helper.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_remote_control_helper.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_audio_setting.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_live_transcription_helper.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_share_setting.cpp",
			  "./lib/node_add_on/zoom_video_sdk_v8_to_c.cpp",
			  
			  "./lib/node_add_on/zoom_video_sdk_node_video_raw_data.cpp",
			  #"./lib/node_add_on/zoom_video_sdk_node_audio_raw_data.cpp",
			  "./lib/node_add_on/zoom_video_sdk_node_rawdata_server_mgr.cpp",
			   "./lib/node_add_on/raw_data_format.cpp",
			  "./lib/node_add_on/uv_ipc_common.cpp",
			  "./lib/node_add_on/raw_data_uv_ipc_server.cpp",
			  "./lib/node_add_on/zoom_video_sdk_napi_util_exporter.cpp",
			  
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_sdk_wrap_core.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_session_info_wrap_core.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_audio_helper_wrap_core.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_video_helper_wrap_core.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_share_helper_wrap_core.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_video_raw_data_helper.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_user_helper_wrap_core.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_chat_helper_wrap_core.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_livestream_helper_wrap_core.cpp",
			  #"./lib/node_add_on/node_core/zoom_video_sdk_native_video_source_helper.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_cmd_channel_helper_wrap_core.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_phone_helper_wrap_core.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_recording_helper_wrap_core.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_remote_camera_control_helper_wrap_core.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_audio_setting_wrap_core.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_live_transcription_helper_wrap_core.cpp",
			  "./lib/node_add_on/node_core/zoom_video_sdk_native_share_setting_wrap_core.cpp",
		  ],
			  'defines':['BUILD_WIN'],
			  
			   'include_dirs':[
			   "./lib/node_add_on/protobuf_src",
			   "./lib/node_add_on",
			   "./lib/node_add_on/export_h",
				],
		  }
		  
		  ]

		 ]
      },
	  
	   {
	 'target_name':"<(render_module_name)",
	 
	 'conditions':[
	  [
		  'OS=="mac"',
		  {
		      # 'product_dir':"<(module_mac)",
		      "dependencies": [ "<(napi_util_module_name)" ],
			  'sources':[
			     "./lib/node_add_on/zoom_video_sdk_node_libuv_addon.cpp",
			     "./lib/node_add_on/uv_ipc_common.cpp",
			     "./lib/node_add_on/electron_zoomvideosdk.pb.cc",
			     "./lib/node_add_on/zoom_video_sdk_napi_util_exporter.cpp",
			  ],
			  'defines':['__MACOS__'],
			  # 'mac_framework_dirs':[
			  # './../sdk/mac/ZoomSDK',
			  # ],
			  'mac_bundle_resources': [
     			"../sdk/mac/zoomsdk_napi_util.node",
    			],
			  'link_settings':{
			  'libraries':[
			      "../sdk/mac/ZoomVideoSDK/VideoSDK.dylib",
			      "../sdk/mac/ZoomVideoSDK/libprotobuf.dylib"
			   ],
			   'include_dirs':[
			   "./lib/node_add_on/protobuf_src",
			   "./lib/node_add_on",
			   "./lib/node_add_on/export_h",
				],
			   },
			   "xcode_settings":{
                    "DEBUG_INFORMATION_FORMAT": "dwarf-with-dsym",
                    "BUILD_DIR":"<(module_mac)",
                    "OTHER_CPLUSPLUSFLAGS" : [ '-ObjC++', "-std=c++20", "-stdlib=libc++",  '-fvisibility=hidden','-frtti'],
                    "OTHER_LDFLAGS": [ "-stdlib=libc++"],
                    "DEPLOYMENT_POSTPROCESSING": "YES",
	        }
			   
		  },
		  ],
      [
		  'OS=="linux"',
		  {
		    'sources':[
			     "./lib/node_add_on/zoom_video_sdk_node_libuv_addon.cpp",
			     "./lib/node_add_on/uv_ipc_common.cpp",
			     "./lib/node_add_on/electron_zoomvideosdk.pb.cc",
			     "./lib/node_add_on/zoom_video_sdk_napi_util_exporter.cpp",
			  ],
			  'link_settings':{
          'libraries':[
			       "../sdk/linux/libprotobuf.a",
			    ],
			   'include_dirs':[
			   "./lib/node_add_on/protobuf_src",
			   "./lib/node_add_on",
			   "./lib/node_add_on/export_h",
				],
			  },
				'cflags_cc!': ['-fno-rtti']
		  }
		  ],
		  [
		  'OS=="win" and target_arch=="ia32"',
		  {
		     'configurations': {
				'Release': {
				  'msvs_settings': {
					'VCLinkerTool': {
					  'GenerateDebugInformation': 'true',
					  'GenerateMapFile': 'true',
					  'ProgramDatabaseFile': "<(render_module_32pdbfile_name)",
					},
					'VCCLCompilerTool': {
                     'RuntimeLibrary': '2',
                    },
				  }, 
				},
		  }, # configurations
		  'link_settings':{
			  'libraries':[
			   "./../sdk/win32/libprotobuf-lite.lib",
			   "./../sdk/win32/zoomvideosdk_napi_util.lib",
			   ],
			   },
		  }
		  ],
		  [
		  'OS=="win" and target_arch=="x64"',
		  {
		     'configurations': {
				'Release': {
				  'msvs_settings': {
					'VCLinkerTool': {
					  'GenerateDebugInformation': 'true',
					  'GenerateMapFile': 'true',
					  'ProgramDatabaseFile': "<(render_module_64pdbfile_name)",
					},
					'VCCLCompilerTool': {
                     'RuntimeLibrary': '2',
                    },
				  }, 
				},
		  }, # configurations
		  'link_settings':{
			  'libraries':[
			   "./../sdk/win64/libprotobuf-lite.lib",
               "./../sdk/win64/zoomvideosdk_napi_util.lib",
			   ],
			   },
		  }
		  ],
		  [
		  'OS=="win"',
		  {
		  "dependencies": [ "<(napi_util_module_name)" ],
		  "sources":[
			
			  "./lib/node_add_on/zoom_video_sdk_node_libuv_addon.cpp",
			  "./lib/node_add_on/uv_ipc_common.cpp",
			  "./lib/node_add_on/electron_zoomvideosdk.pb.cc",
			  "./lib/node_add_on/zoom_video_sdk_napi_util_exporter.cpp",
		  ],
			  
			'defines':['BUILD_WIN'],  
			 
			   'include_dirs':[
			   "./lib/node_add_on/protobuf_src",
			   "./lib/node_add_on",
			   "./lib/node_add_on/export_h",
				],
		  
		  }
		  
		  ]
	 ]
	 },
	 {
      "target_name": "copy_binary",
      "type": "none",
	  'conditions':
	  [
		[
		'OS=="win" and target_arch=="ia32"',
		{
		"dependencies": [ "<(module_name)", "<(render_module_name)" ],
			"copies": 
			[
				{
					"files": [ "<(PRODUCT_DIR)/zoomvideosdk.node", "<(PRODUCT_DIR)/zoomvideosdk.lib", "<(PRODUCT_DIR)/zoomvideosdk_libuv.node", "<(PRODUCT_DIR)/zoomvideosdk_libuv.lib" ],
					"destination": "./sdk/win32/"
				}
			]
		}
		],
		[
		'OS=="win" and target_arch=="x64"',
		{
		"dependencies": [ "<(module_name)", "<(render_module_name)" ],
			"copies": 
			[
				{
					"files": [ "<(PRODUCT_DIR)/zoomvideosdk.node", "<(PRODUCT_DIR)/zoomvideosdk.lib", "<(PRODUCT_DIR)/zoomvideosdk_libuv.node", "<(PRODUCT_DIR)/zoomvideosdk_libuv.lib" ],
					"destination": "./sdk/win64/"
				}
			]
		}
		]
	  ]	
    }
      ]
}
