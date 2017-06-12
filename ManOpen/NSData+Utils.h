#import <Foundation/Foundation.h>

@interface NSData (Utils)

/*!
 * Checks the data to see if it looks like the start of an nroff file.
 * Derived from logic in FreeBSD's <b>file(1)</b> command.
 */
@property (getter=isNroffData, readonly) BOOL nroffData;
@property (getter=isRTFData, readonly) BOOL RTFData;
@property (getter=isGzipData, readonly) BOOL gzipData;
//! Very rough check -- see if more than a third of the first 100 bytes have the high bit set
@property (getter=isBinaryData, readonly) BOOL binaryData;

@end

@interface NSFileHandle (Utils)

/*!
 * The <code>-[NSData readDataToEndOfFile]</code> method does not deal with \c EINTR errors, which in most
 * cases is fine, but sometimes not when running under a debugger.  So... this is more to help
 * folks working on the code, rather the users ;-)
 */
- (nullable NSData *)readDataToEndOfFileIgnoreInterruptAndReturnError:(NSError * __nullable * __nullable)error;

@end
