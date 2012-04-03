
/*!
 \mainpage
 <H1>RSA SecurID SDK X.Y for iOS Developer's Guide</H1>
 <p>The RSA SecurID SDK for iOS enables third-party vendors to develop a user interface for a SecurID software token application that runs on iOS 3.0 or later.
 This SDK provides the ability to import SecurID software tokens to a device and retrieve one-time passwords (OTPs) to use for RSA SecurID authentication.
 
 <H2>What's New in Version X.Y</H2> 
 <ul>
 <li>This release supports migration from SDK version 1.0, 1.1 and 1.3.</li>
 <li>TBD</li>
 </ul>
 
 
 <H2>Supported Platforms</H2>
 <ul>
   <li>iPhone 3G/3GS running iOS 3.0 or later</li>
   <li>iPhone 4 running iOS 4.0 or later</li>
   <li>iPad running iOS 3.2 or later</li>
   <li>iPad 2 running iOS 4.3.3 or later</li>
   <li>iPod touch running iOS 4.0 or later</li>
   <li>Any iPhone, iPad, or iPod touch device running iOS 5.0</li>
 </ul>

 <H2>RSA Product Dependencies</H2>
 <ul>
  <li>One of the following:</li>
  <ul>
    <li>RSA Authentication Manager 6.1</li>
	<li>RSA Authentication Manager 7.1 SP3 or later</li>
    <li>RSA SecurID Appliance 3.0</li> 
    <li>RSA SecurID Authentication Engine 2.6 for Java</li>
  </ul>
  <li>RSA SecurID Software Token Converter 2.6</li>
 </ul>

 <H2>Features of the SDK</H2>
 <p>The SDK allows you to:
 <ul>
   <li>Import a software token file (SDTID file).
   <li>Import a software token file (SDTID file) that has been converted to Compressed Token Format (CTF). This provisioning mechanism requires the RSA SecurID Software Token Converter command line utility.
   <li>Import a software token using Dynamic Seed Provisioning. This provisioning mechanism uses the Cryptographic Token Key Initialization Protocol (CT-KIP). The software token application running on the device (the client) and Authentication
 Manager (the server) use a four-pass CT-KIP protocol to exchange information that is used to dynamically generate a unique seed (shared secret) on the client and the server.</li>
   <li>Get the tokencode or passcode for a SecurID token. A tokencode is a pseudorandom number generated by a software token at regular intervals. A passcode is a combination of a PIN and the current tokencode. The current tokencode or passcode is the one-time password (OTP) that is used for SecurID authentication.
   </li>
   <li>Retrieve a list of software tokens installed on the device.</li>
   <li>Remove a software token installed on the device identified by serial number.</li>
   <li>Obtain the unique device identifier for binding a software token to a specific device.  A token bound to the device's unique identifier cannot be imported to any other device.</li>
   <li>Obtain the SecurID library version.</li>
 </ul>
 <hr>

 <H2>Supported Software Token Types</H2>
 The SDK supports a maximum of 10 128-bit software tokens. The SDK does not support 64-bit software tokens. 
 <p>The tokens can be any of the following types:
 <ul>
   <li>PINPad-style. Emulates the behavior of a SecurID hardware token that contains a numeric keypad. The user enters a PIN in the device 
   to generate the OTP (passcode). PINPad-style software tokens require a 4-8 digit PIN.</li> 
   <li>Fob-style. Emulates the behavior of a SecurID hardware token that does not contain a numeric keypad. The user enters a PIN and the 
   current tokencode in the application that is requesting authentication credentials. The OTP is the concatenation of the PIN and tokencode. 
   Fob-style software tokens require a 4-8 digit numeric PIN or a 4-8 character alphanumeric PIN.</li>
   <li>PINless. The user enters only the OTP (tokencode) in the application that is requesting authentication credentials.</li>
 </ul>

 <p>RSA Authentication Manager 6.1 supports:
 <ul>
   <li>File-based provisioning (SDTID files). If you provision tokens using CTF, you must use the Token Converter utility.</li>
   <li>PINPad-style and PINless software tokens</li>
   <li>8-digit tokencode (OTP) length</li>
   <li>60-second tokencode intervals</li>
 </ul>
  
 RSA Authentication Manager 7.1 supports:
 <ul>
   <li>Dynamic Seed Provisioning
   <li>File-based provisioning. If you provision tokens using CTF, you must use the Token Converter utility.</li>
   <li>PINPad-style, fob-style, and PINless software tokens</li>
   <li>6/8-digit tokencode (OTP) length</li>
   <li>30/60-second tokencode intervals</li>
 </ul>
  

 <H2>RSA SecurID Software Token Converter Requirements</H2>
 <p>Before you can import a software token using CTF, you must use the RSA SecurID Software Token Converter 2.6 to
 convert the token file (SDTID file) to Compressed Token Format (an 81-digit numeric string that can be sent to a device). Download the Token Converter
 from http://rsa.com/node.aspx?id=1313 and follow the instructions in the Token Converter Readme. Use either the -mobile option or the -iphone
 option to convert the token file. Delete the URL information at the beginning of the converted token data (for example, com.rsa.securid://ctf?ctfData=)
 and use only the 81-digit string.
 <br> 
 <br>
 
 <hr>
 <H2>Using SecurIDLib</H2>
 <p>The following table lists the methods that an application may use.

 <table cellpadding="2" cellspacing="2" border="1">
 <tr>
 <th>Class Methods</th>
 <th>Description</th>
 </tr>

 <tr>
 <td valign="top"><b>+ getLibraryInfo:minor:</b>
 </td>
 <td valign="top">Retrieve the library version information.
 </td>
 </tr>

 <tr>
 <td valign="top"><b>+ getDeviceId</b>
 </td>
 <td valign="top">Retrieve unique device identifier for device binding.
 </td>
 </tr>
 
 <tr>
 <td valign="top"><b>+ getInstance</b>
 </td>
 <td valign="top">Get instance of SecurIDLib.
 </td>
 </tr>

 </table> 
 <br> 

 <table cellpadding="2" cellspacing="2" border="1">
 <tr>
 <th>Instance Methods</th>
 <th>Description</th>
 </tr>
 
 <tr>
 <td valign="top"><b>- importTokenFromFile:filePassword:serialNumber:</b>
 </td>
 <td valign="top">Provision a token from an SDTID file.
 </td>
 </tr>
 
 <tr>
 <td valign="top"><b>- importTokenFromCtf:ctfPassword:serialNumber:</b>
 </td>
 <td valign="top">Provision a token using CTF.
 </td>
 </tr>

 <tr>
 <td valign="top"><b>- importTokenFromCtkip:ctkipAuthCode:validateCert:delegate:</b>
 </td>
 <td valign="top">Provision a token using CT-KIP.
 </td>
 </tr>

 <tr>
 <td valign="top"><b>- getTokenList</b>
 </td>
 <td valign="top">Retrieve a list of tokens installed on the device.
 </td>
 </tr>

 <tr>
 <td valign="top"><b>- getOtp:pin:otp:secs:</b>
 </td>
 <td valign="top">Generate an OTP for a token.
 </td>
 </tr>

 <tr>
 <td valign="top"><b>- getNextOtp:pin:otp:secs:</b>
 </td>
 <td valign="top">Generate the next OTP for a token.
 </td>
 </tr>

 <tr>
 <td valign="top"><b>- generateSignature:td:pin:sig:</b>
 </td>
 <td valign="top">Generate signature (8-digits) for raw transaction data.
 </td>
 </tr> 
 
 <tr>
 <td valign="top"><b>- generateSignatureExt:td:pin:sig:</b>
 </td>
 <td valign="top">Generate extended signature (16-bytes) for raw transaction data.
 </td>
 </tr>  
 
 <tr>
 <td valign="top"><b>- generateSignatureForTransactionDataPayload:pin:sig:</b>
 </td>
 <td valign="top">Generate signature (8-digits) for transaction data payload.
 </td>
 </tr>  
 
 <tr>
 <td valign="top"><b>- generateSignatureForTransactionDataPayloadExt:pin:sig:</b>
 </td>
 <td valign="top">Generate extended signature (16-bytes) for transaction data payload.
 </td>
 </tr>  
 
 <tr>
 <td valign="top"><b>- getDataFromTransactionDataPayload:td</b>
 </td>
 <td valign="top">Get data from transaction data payload.
 </td>
 </tr>   
 
 
 </table>

 <br>
 <hr>

 <H2>Getting Started with the SDK</H2>

 <H3>Package Contents</H3>
 <p>The SDK kit contains the following folders:
 <ul>
   <li>doc - SDK documentation</li>
   <li>inc - include files</li>
   <li>lib - OS and simulator libraries</li>
   <li>sample - sample project</li>
 </ul>

 <H3>Development Environment</H3>
 <ul>
   <li>Mac OS X Lion (10.7.2 or later)</li>
   <li>Xcode 4.2 or later</li>
   <li>iOS SDK 5.0 or later</li>
 </ul>

 <H3>Bulding the Sample Application</H3>
 <ol>
   <li>Create a <b>Library</b> directory in the sample project folder.</li>
   <li>Copy the SDK include files, schema file, and appropriate SecurIDLib static library (OS or simulator build) to the created directory.</li>
     <ul>
       <li>SecurIDLib.h</li>
       <li>SecurIDTokenProtocol.h</li>
       <li>SecurIDLibStatus.h</li>
       <li>TransactionSigningTdp.xsd</li>
       <li>libSecurIDLib.a</li>
	 </ul>
   <li>Open the project (SampleApp.xcodeproj) with Xcode.</li>
   <li>The sample project has been set up with the appropriate build settings and dependencies for compiling the application.
       If needed, follow these instructions to add the necessary build settings and dependencies.</li>
     <ol type="a">
       <li>In the project navigator, select your project.</li>
       <li>Select your target.</li>
	   <li>Select the <b>Build Settings</b> tab.</li>
       <li>To support older iOS devices that are running on an armv6 CPU, modify the architecture to include armv6.</li>
       <ul>
       <li>Open the <b>Architectures</b> expander.</li>
       <li>For the <b>Architectures</b> setting, add <b>armv6</b>. </li>   
       </ul>
       <li>To support devices running on iOS 3.1.x or before, use the LLVM compiler.</li>
       <ul>
       <li>Open the <b>Build Options</b> expander.</li>
       <li>For the <b>Compiler for C/C++/Objective-C</b> setting, select <b>LLVM GCC 4.2</b>. </li>   
       </ul> 
       <li>Open the <b>Linking</b> expander.</li>
       <li>For the <b>Other Linker Flags</b> setting, enter <b>-lSecurIDLib</b>.</li>
       <li>Select the <b>Build Phases</b> tab.</li>
       <li>Open the <b>Link Binary With Libraries</b> expander.</li> 
       <li>Add the following frameworks and libraries as dependencies:</li>
         <ul>
         <li><b>CFNetwork.framework</b></li>
         <li><b>SystemConfiguration.framework</b></li>
         <li><b>Security.framework</b></li>
         <li><b>MobileCoreServices.framework</b></li>
         <li><b>libz.dylib</b></li>
         <li><b>libsqlite3.dylib</b></li>
         <li><b>libxml2.dylib</b></li>
         </ul>
       <li>Open the <b>Copy Bundle Resources</b> expander.</li> 
       <li>Verify the following schema file is included in the Bundle:</li>
         <ul>
         <li><b>TransactionSigningTdp.xsd</b></li>
         </ul> 
     </ol>
   <li>Build the application for simulator or device. The Code Signing Identity will need to be specified if building for a device.</li> 
 </ol>

 <H3>Integrating SecurID into Your Application</H3>

 <ol>
 <li>Add the following SDK include and schema files to your project:</li>
   <ul>
     <li>SecurIDLib.h</li>
     <li>SecurIDTokenProtocol.h</li>
     <li>SecurIDLibStatus.h</li>
     <li>TransactionSigningTdp.xsd</li>
   </ul>
 <li>Copy the appropriate SecurIDLib static library (OS or simulator build) to your project folder.</li>
   <ul>
     <li>libSecurIDLib.a</li>
   </ul>
 <li>Modify build settings and dependencies to compile the application.</li> 
   <ol type="a">
     <li>In the project navigator, select your project.</li>
     <li>Select your target.</li>
     <li>Select the <b>Build Settings</b> tab.</li> 
     <li>To support older iOS devices that are running on an armv6 CPU, modify the architecture to include armv6.</li>
     <ul>
     <li>Open the <b>Architectures</b> expander.</li>
     <li>For the <b>Architectures</b> setting, add <b>armv6</b>. </li>   
     </ul>
     <li>To support devices running on iOS 3.1.x or before, use the LLVM compiler.</li>
     <ul>
     <li>Open the <b>Build Options</b> expander.</li>
     <li>For the <b>Compiler for C/C++/Objective-C</b> setting, select <b>LLVM GCC 4.2</b>. </li>   
     </ul> 
     <li>Open the <b>Linking</b> expander.</li>
     <li>For the <b>Other Linker Flags</b> setting, enter <b>-lSecurIDLib</b>.</li>
     <li>Select the <b>Build Phases</b> tab.</li>
     <li>Open the <b>Link Binary With Libraries</b> expander.</li> 
     <li>Add the following frameworks and libraries as dependencies:</li>
       <ul>
         <li><b>CFNetwork.framework</b></li>
         <li><b>SystemConfiguration.framework</b></li>
         <li><b>Security.framework</b></li>
         <li><b>MobileCoreServices.framework</b></li>
         <li><b>libz.dylib</b></li>
         <li><b>libsqlite3.dylib</b></li>
         <li><b>libxml2.dylib</b></li>
       </ul>
     <li>Open the <b>Copy Bundle Resources</b> expander.</li> 
     <li>Verify the following schema file is included in the Bundle:</li>
         <ul>
           <li><b>TransactionSigningTdp.xsd</b></li>
         </ul>
   </ol>
 <li>The SDK is dependent on C++ classes. Any objective-C implementation using the SDK should have an extension of <b>.mm</b>. </li>
 </ol>

 
 <H3>Secure Coding Practice</H3>
 <p>RSA strongly recommends that you strip all debug symbols when you build your final application to help ensure
 the security of your code. Apply the following settings and values to your release product build configuration:
 <ol>
 <li>In the project navigator, select your project.</li>
 <li>Select your target.</li>
 <li>Select the <b>Build Settings</b> tab.</li>
 <li>Open the <b>Deployment</b> expander and apply the following settings to your build configuration:
 <ul>
 <li>Expand the <b>Deployment Postprocessing</b> field and set the value to <b>Yes</b>.</li>
 <li>Expand the <b>Strip Debug Symbols During Copy</b> field and set the value to <b>Yes.</b></li>
 <li>Expand the <b>Strip Linked Product</b> field and set the value to <b>Yes</b>.</li>
 <li>Expand the <b>Strip Style</b> field and set the value to <b>All Symbols</b>.</li>
 <li>Expand the <b>Use Separate Strip</b> field and set the value to <b>Yes</b>.</li>
 </ul>
 </li>
 <li>Open the <b>Linking</b> expander.
 <ul>
 <li>Expand the <b>Dead Code Stripping</b> field and set the value to <b>Yes</b>.</li>
 </ul> 
 </li>
 <li>Open the <b>Code Generation</b> expander for the selected compiler.
 <ul>
 <li>Expand the <b>Generate Debug Symbols</b> field and set the value to <b>No</b>.</li>
 </ul>
 </li>
 </ol>
 
 <br>
 
 <hr>

 This software and the associated documentation are proprietary and confidential to EMC,
 are furnished under license, and may be used and copied only in accordance with the terms
 of such license and with the inclusion of the copyright notice below. This software and the
 documentation, and any copies thereof, may not be provided or otherwise made available to
 any other person.

 No title to or ownership of the software or documentation or any intellectual property rights
 thereto is hereby transferred. Any unauthorized use or reproduction of this software and the
 documentation may be subject to civil and/or criminal liability.
 This software is subject to change without notice and should not be construed as a commitment by EMC.

 Copyright (c) 2010-2012 EMC Corporation. All Rights Reserved.
 */




#import <Foundation/Foundation.h>
#import "SecurIDTokenProtocol.h"
#import "SecurIDLibStatus.h"




@protocol SecurIDLibDelegate;


@interface SecurIDLib : NSObject {

@private
    NSObject* mCp;
    NSObject* mOp;
    NSObject* mCtp;
	NSObject* mFp;
    NSObject* mTa;
}



//--------------------
// class level methods
//--------------------
/*! \brief Get instance of a SecurIDLib object.
 *
 *  \return Return a singleton instance of a SecurIDLib object.
 */
+ (SecurIDLib*)getInstance;

/*! \brief Get library version information.
 *
 *  \param [out] majorVersion Return major version number if parameter is not nil.
 *  \param [out] minorVersion Return minor version number if parameter is not nil.
 */
+ (void)getLibraryInfo:(int*)majorVersion minor:(int*)minorVersion;

/*! \brief Get device-specific binding information.
 *
 *  \return Returns a device-specific identifier that can be used to bind a token to a device. For devices running iOS 3.x, the device-specific identifier is the Universal Device Identifier (UDID). For devices running iOS 4.x or later, the device-specific identifier is a Device ID provided by RSA.
 */
+ (NSString *)getDeviceId;

//-----------------
// instance methods
//-----------------
/*! \brief Import a token from a CTF record.
 *
 *  \param [in] ctfData CTF record. This parameter must not be nil.
 *  \param [in] ctfPassword Password for decrypting the CTF record if the record is password protected. Maximum password length is 24 characters. This parameter is a UTF8-encoded string.
 *  \param [out] serialNumber The mutable string object that receives the serial number of the token that was imported. The serial number is also returned if a duplicate token error is encountered. This parameter must not be nil.
 *  \return Return SECURIDLIB_ERR_SUCCESS if successful.  Error codes that may be returned include:<br>
 *          SECURIDLIB_ERR_FAILURE,<br>
 *          SECURIDLIB_ERR_PARAMETER_CTF,<br>
 *          SECURIDLIB_ERR_PARAMETER_SN,<br>
 *          SECURIDLIB_ERR_CTF_PARSE,<br>
 *          SECURIDLIB_ERR_CTF_DEVICEID,<br>
 *          SECURIDLIB_ERR_CTF_PASSWORD,<br>
 *          SECURIDLIB_ERR_TOKEN_EXPIRED,<br>
 *          SECURIDLIB_ERR_COPY_PROTECTION,<br>
 *          SECURIDLIB_ERR_PERSISTENCE,<br>
 *          SECURIDLIB_ERR_DUPLICATE_TOKEN,<br>
 *          SECURIDLIB_ERR_MAX_TOKEN_LIMIT,<br>
 *          SECURIDLIB_ERR_DATA_PROTECTION<br>
 */
- (SECURIDLIB_STATUS)importTokenFromCtf:(NSString*)ctfData ctfPassword:(NSString*)ctfPassword serialNumber:(NSMutableString*)serialNumber;

/*! \brief Initiate import of a token using CT-KIP.  If CT-KIP has been successfully initiated, the delegate will be notified
 *         upon completion of the operation.
 *
 *  \param [in] ctkipUrl CT-KIP server URL. This parameter is a UTF8-encoded string and must not be nil.
 *  \param [in] ctkipAuthCode Activation code for provisioning of a token using CT-KIP. This parameter is required and must not be nil.
 *  \param [in] validateCert YES enables SSL certificate validation. If a SECURIDLIB_ERR_CTKIP_SSL_CERTIFICATE is returned,
 *         the application should prompt the user to proceed with the untrusted certificate. The application can retry the import with
 *         this parameter set to NO if the user accepts the untrusted certificate.
 *  \param [in] delegateToNotify Delegate to be notified upon completion of the CT-KIP operation. The delegate is an NSObject that conforms to SecurIDLibDelegate
 *              protocol and must not be nil.
 *  \return Return SECURIDLIB_ERR_SUCCESS if CT-KIP has been successfully initiated. Error codes that may be returned, either from this method
 *          or to the delegate to be notified, include:<br>
 *          SECURIDLIB_ERR_FAILURE,<br>
 *          SECURIDLIB_ERR_PARAMETER_URL,<br>
 *          SECURIDLIB_ERR_PARAMETER_AUTHCODE,<br>
 *          SECURIDLIB_ERR_PARAMETER_DELEGATE,<br>
 *          SECURIDLIB_ERR_CTKIP_WIRELESS_SERVICE,<br>
 *          SECURIDLIB_ERR_COPY_PROTECTION,<br>
 *          SECURIDLIB_ERR_CTKIP_PACKET_PROCESSING,<br>
 *          SECURIDLIB_ERR_CTKIP_EXCEPTION,<br>
 *          SECURIDLIB_ERR_CTKIP_INVALID_AUTHCODE,<br>
 *          SECURIDLIB_ERR_CTKIP_NETWORK,<br>
 *          SECURIDLIB_ERR_CTKIP_SSL_CERTIFICATE,<br>
 *          SECURIDLIB_ERR_CTKIP_DEVICEID,<br>
 *          SECURIDLIB_ERR_TOKEN_EXPIRED,<br>
 *          SECURIDLIB_ERR_PERSISTENCE,<br>
 *          SECURIDLIB_ERR_DUPLICATE_TOKEN,<br>
 *          SECURIDLIB_ERR_MAX_TOKEN_LIMIT,<br>
 *          SECURIDLIB_ERR_DATA_PROTECTION<br>
 */
- (SECURIDLIB_STATUS)importTokenFromCtkip:(NSString*)ctkipUrl ctkipAuthCode:(NSString*)ctkipAuthCode
                          validateCert:(BOOL)validateCert delegate:(NSObject<SecurIDLibDelegate> *)delegateToNotify;

/*! \brief Import a token from an SDTID file (XML format).  If the file contains multiple tokens, only the first token is imported. 64-bit tokens are not supported.
 *
 *  \param [in] fileData An NSData object containing token file (SDTID file) data. This parameter must not be nil.
 *  \param [in] filePassword Token file password. Maximum password length is 24 characters. This parameter is a UTF8-encoded string.
 *  \param [out] serialNumber The mutable string object that receives the serial number of the token that was imported. The serial number is also returned if a duplicate token error is encountered. This parameter must not be nil.
 *  \return Return SECURIDLIB_ERR_SUCCESS if successful.  Error codes that may be returned include:<br>
 *          SECURIDLIB_ERR_FAILURE,<br>
 *          SECURIDLIB_ERR_PARAMETER_FILE,<br>
 *          SECURIDLIB_ERR_PARAMETER_SN,<br>
 *          SECURIDLIB_ERR_FILE_PARSE,<br>
 *          SECURIDLIB_ERR_FILE_DEVICEID,<br>
 *          SECURIDLIB_ERR_FILE_PASSWORD,<br>
 *          SECURIDLIB_ERR_TOKEN_EXPIRED,<br>
 *          SECURIDLIB_ERR_COPY_PROTECTION,<br>
 *          SECURIDLIB_ERR_PERSISTENCE,<br>
 *          SECURIDLIB_ERR_DUPLICATE_TOKEN,<br>
 *          SECURIDLIB_ERR_MAX_TOKEN_LIMIT,<br>
 *          SECURIDLIB_ERR_DATA_PROTECTION<br>
 */
- (SECURIDLIB_STATUS)importTokenFromFile:(NSData*)fileData filePassword:(NSString*)filePassword serialNumber:(NSMutableString*)serialNumber;


/*! \brief Get OTP.
 *
 *  \param [in] serialNumber Token serial number. This parameter must not be nil.
 *  \param [in] pin User's SecurID PIN. This parameter is optional. For a PINless token, the PIN is ignored.
 *              For a fob-style token, the PIN is prepended to the OTP unless the PIN is all zeros. For a PINpad-style token, the PIN is combined
 *              with the OTP.
 *  \param [out] otp The mutable string object that receives the current OTP. This parameter must not be nil.
 *  \param [out] secsRemaining Seconds remaining before the current OTP changes. This parameter must not be nil.
 *  \return Return SECURIDLIB_ERR_SUCCESS if successful. Error codes that may be returned include:<br>
 *          SECURIDLIB_ERR_FAILURE,<br>
 *          SECURIDLIB_ERR_PARAMETER_SN,<br>
 *          SECURIDLIB_ERR_PARAMETER_PIN,<br>
 *          SECURIDLIB_ERR_PARAMETER_OTP,<br>
 *          SECURIDLIB_ERR_PARAMETER_SECS,<br>
 *          SECURIDLIB_ERR_NO_TOKEN,<br>
 *          SECURIDLIB_ERR_TOKEN_EXPIRED<br>
 */
- (SECURIDLIB_STATUS)getOtp:(NSString*)serialNumber pin:(NSString*)pin otp:(NSMutableString*)otp secs:(NSUInteger*)secsRemaining;

/*! \brief Get next OTP.
 *
 *  \param [in] serialNumber Token serial number. This parameter must not be nil.
 *  \param [in] pin User's SecurID PIN. This parameter is optional. For a PINless token, the PIN is ignored.
 *              For a fob-style token, the PIN is prepended to the OTP unless the PIN is all zeros. For a PINpad-style token, the PIN is combined
 *              with the OTP.
 *  \param [out] otp The mutable string object that receives the next OTP. This parameter must not be nil.
 *  \param [out] secsRemaining Seconds remaining before the next OTP changes. This parameter must not be nil.
 *  \return Return SECURIDLIB_ERR_SUCCESS if successful. Error codes that may be returned include:<br>
 *          SECURIDLIB_ERR_FAILURE,<br>
 *          SECURIDLIB_ERR_PARAMETER_SN,<br>
 *          SECURIDLIB_ERR_PARAMETER_PIN,<br>
 *          SECURIDLIB_ERR_PARAMETER_OTP,<br>
 *          SECURIDLIB_ERR_PARAMETER_SECS,<br>
 *          SECURIDLIB_ERR_NO_TOKEN,<br>
 *          SECURIDLIB_ERR_TOKEN_EXPIRED<br>
 */
- (SECURIDLIB_STATUS)getNextOtp:(NSString*)serialNumber pin:(NSString*)pin otp:(NSMutableString*)otp secs:(NSUInteger*)secsRemaining;

/*! \brief Generate signature (8-digits) for raw transaction data.
 *
 *  \param [in] serialNumber Token serial number. This parameter is required.
 *  \param [in] td Transaction data (UTF-8 encoded). This parameter is required. WHAT IS MIN/MAX LENGTH?
 *  \param [in] pin User's SecurID PIN. This parameter is optional.
 *  \param [out] sig The mutable string object that receives the signature. This parameter is required.
 *  \return Return SECURIDLIB_ERR_SUCCESS if successful. Error codes that may be returned include:<br>
 *          SECURIDLIB_ERR_FAILURE,<br>
 *          TBD<br>
 */
- (SECURIDLIB_STATUS)generateSignature:(NSString*)serialNumber td:(NSData*)td pin:(NSString*)pin sig:(NSMutableString*)sig;

/*! \brief Generate extended signature (16-bytes) for raw transaction data.
 *
 *  \param [in] serialNumber Token serial number. This parameter is required.
 *  \param [in] td Transaction data (UTF-8 encoded). This parameter is required. WHAT IS MIN/MAX LENGTH?
 *  \param [in] pin User's SecurID PIN. This parameter is optional.
 *  \param [out] sig The mutable NSData object that receives the signature. This parameter is required.
 *  \return Return SECURIDLIB_ERR_SUCCESS if successful. Error codes that may be returned include:<br>
 *          SECURIDLIB_ERR_FAILURE,<br>
 *          TBD<br>
 */
- (SECURIDLIB_STATUS)generateSignatureExt:(NSString*)serialNumber td:(NSData*)td pin:(NSString*)pin sig:(NSMutableData*)sig;

/*! \brief Generate signature (8-digits) for transaction data payload.
 *
 *  \param [in] tdp Transaction data payload (UTF-8 encoded). This parameter is required. WHAT IS MIN/MAX LENGTH?
 *  \param [in] pin User's SecurID PIN. This parameter is optional.  WHAT IS MIN/MAX LENGTH?
 *  \param [out] sig The mutable string object that receives the signature. This parameter must not be nil.
 *  \return Return SECURIDLIB_ERR_SUCCESS if successful. Error codes that may be returned include:<br>
 *          SECURIDLIB_ERR_FAILURE,<br>
 *          TBD<br>
 */
- (SECURIDLIB_STATUS)generateSignatureForTransactionDataPayload:(NSData*)tdp pin:(NSString*)pin sig:(NSMutableString*)sig;

/*! \brief Generate extended signature (16-bytes) for transaction data payload.
 *
 *  \param [in] tdp Transaction data payload (UTF-8 encoded). This parameter is required. WHAT IS MIN/MAX LENGTH?
 *  \param [in] pin User's SecurID PIN. This parameter is optional.  WHAT IS MIN/MAX LENGTH?
 *  \param [out] sig The mutable NSData object that receives the signature. This parameter is required.
 *  \return Return SECURIDLIB_ERR_SUCCESS if successful. Error codes that may be returned include:<br>
 *          SECURIDLIB_ERR_FAILURE,<br>
 *          TBD<br>
 */
- (SECURIDLIB_STATUS)generateSignatureForTransactionDataPayloadExt:(NSData*)tdp pin:(NSString*)pin sig:(NSMutableData*)sig;

/*! \brief Get data from transaction data payload (TDP).
 *
 *  \param [in] tdp Transaction data payload (UTF-8 encoded). This parameter is required. WHAT IS MIN/MAX LENGTH?
 *  \param [out] td Transaction data dictionary. The mutable dictionary object that receives the transaction data. This parameter is required.  Use the following keys to retrieve information from the dictionary:<br>
 *          SECURIDLIB_TDP_VERSION_KEY - NSString object containing TDP version<br>
 *          SECURIDLIB_TDP_TIME_KEY - NSString object containing TDP time<br>
 *          SECURIDLIB_TDP_SERIAL_NUMBER_KEY - NSString object containing token serial number<br>
 *          SECURIDLIB_TDP_TRANSACTION_ID_KEY - NSString object containing transaction ID<br>
 *          SECURIDLIB_TDP_TRANSACTION_DATA_KEY - NSData object containing transaction data
 *  \return Return SECURIDLIB_ERR_SUCCESS if successful. Error codes that may be returned include:<br>
 *          SECURIDLIB_ERR_FAILURE,<br>
 *          SECURIDLIB_ERR_PARAMETER,<br>
 *          SECURIDLIB_ERR_NO_TOKEN,<br>
 *          SECURIDLIB_ERR_TDP_XSD_VALIDATION,<br> 
 *          SECURIDLIB_ERR_TDP_XML_PARSE,<br> 
 *          SECURIDLIB_ERR_TDP_INTEGRITY,<br> 
 *          SECURIDLIB_ERR_TDP_CRYPTO,<br>
 *          SECURIDLIB_ERR_TDP_INVALID_OPERATION<br>
 *
 */
- (SECURIDLIB_STATUS)getDataFromTransactionDataPayload:(NSData*)tdp td:(NSMutableDictionary*)td;

/*! \brief Get a list of installed tokens.
 *
 *  \return Return an array object ID. Objects in the array conform to SecurIDTokenProtocol. The returned array is autoreleased.
 */
- (NSArray*)getTokenList;

/*! \brief Delete the token with the specified serial number.
 *
 *  \param [in] serialNumber Token serial number. This parameter must not be nil.
 *  \return Return SECURIDLIB_ERR_SUCCESS if successful. Error codes that may be returned include:<br>
 *          SECURIDLIB_ERR_FAILURE,<br>
 *          SECURIDLIB_ERR_PARAMETER_SN,<br>
 *          SECURIDLIB_ERR_NO_TOKEN,<br>
 *          SECURIDLIB_ERR_DATA_PROTECTION<br>
 */
- (SECURIDLIB_STATUS)deleteToken:(NSString*)serialNumber;

/*! \brief Remove all installed tokens.
 *
 */
- (void)reset;

@end


/*!
 *  The SecurIDLibDelegate defines the messages to be sent to a callback delegate during provisioning of a token using CT-KIP.
 */
@protocol SecurIDLibDelegate <NSObject>

/*! \brief Provisioning of a token using CT-KIP successfully completed.
 *
 *  \param [in] serialNumber Serial number of the token that was provisioned.
 */
- (void)ctkipImportFinished:(NSString*)serialNumber;

/*! \brief Provisioning of a token using CT-KIP failed.
 *
 *  \param [in] error Error identifying the failure. ([error code] will contain a SECURID_STATUS code)
 */
- (void)ctkipImportFailed:(NSError*)error;


// optional methods
@optional

@end








