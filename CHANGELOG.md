# Changelog

All notable changes to this project are documented here.
Format based on [Keep a Changelog](https://keepachangelog.com).

## [Unreleased]

## [0.1.0] - 2026-07-13
### Added
- Repository standards: README, .gitignore, CONTRIBUTING, issue/PR templates.
- Input validation for stop numbers and fare amounts.
- Bus search-by-ID feature in Rawalpindi Metro menu.
- Reusable fleet-capacity helper function used by the Analytics Dashboard.
- Average capacity-per-bus metric on the Analytics Dashboard.
- CI workflow that verifies required files and compiles the project.

### Fixed
- `RegularMetroBus::display()` no longer prints each stop name twice.
