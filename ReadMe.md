# DSP Stubber

A small class wrapper around AudioFile that can be extended to stub out dsp
algorithms without having to spin up a VST project.

## Testing

### Run test suite
```bash
ctest --test-dir ./build/test/ --output-on-failure
```