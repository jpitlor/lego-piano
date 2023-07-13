export async function getPathOrContent(file: string | File): Promise<string> {
  // If `file` is a string, that means it's the known path of a pre-packaged
  // song. Our library can read from a path, so we can just return this and
  // it will all work out.
  if (typeof file === "string") {
    return file;
  }
}
